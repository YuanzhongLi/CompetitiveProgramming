#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define eb emplace_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define llbidx(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y) // 二要素間の距離
#define deg2rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad2deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)
#define Find(set, element) set.find(element) != set.end()
#define Decimal(x) printf("%.10f\n", x) // 小数点を10桁まで表示

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;

template<class T>
inline bool chmax(T &a, T b) {
  if(a < b) {
    a = b;
    return true;
  }
  return false;
};

template<class T>
inline bool chmin(T &a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
};

static const int MAX_N = 300;
int N;
double dp[MAX_N+1][MAX_N+1][MAX_N+1];

double solve(int o, int t, int h) { // one, two, three
  if (dp[o][t][h] != -1) return dp[o][t][h];
  if (o == 0 && t == 0 && h == 0) return 0;
  double ans = (double)N / (o + t + h); // 状態が変化するまでの回数期待値
  /*
    状態変化が起きたという条件つき確率での、変化先の状態の回数期待値の和をとる
  */
  if (o > 0) ans += 1.0 * o / (o + t + h) * solve(o-1, t, h);
  if (t > 0) ans += 1.0 * t / (o + t + h) * solve(o+1, t-1, h);
  if (h > 0) ans += 1.0 * h / (o + t + h) * solve(o, t+1, h-1);
  dp[o][t][h] = ans;
  return ans;
};

int main() {
  cin >> N;

  rep(i, 0, MAX_N+1) {
    rep(j, 0, MAX_N+1) {
      rep(k, 0, MAX_N+1) {
        dp[i][j][k] = -1;
      }
    }
  }

  int a1 = 0, a2 = 0, a3 = 0;
  rep(i, 0, N) {
    int x;
    cin >> x;
    if (x == 1) a1++;
    if (x == 2) a2++;
    if (x == 3) a3++;
  }

  Decimal(solve(a1, a2, a3));

  return 0;
};
