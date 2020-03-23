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

static const int MAX_N = 2999;

double p[MAX_N+1];
double dp[MAX_N+1][MAX_N+1];

void solve() {
  // dp[i][j]
  dp[0][0] = 1.0;
  rep(i, 1, MAX_N+1) {
    rep(j, 0, i+1) {
      if (j == 0) {
        dp[i][j] = dp[i-1][j] * (1.0 - p[i]);
      } else {
        dp[i][j] = dp[i-1][j-1] * p[i] + dp[i-1][j] * (1.0 - p[i]);
      }
    }
  }
};

int main() {
  int N;
  cin >> N;
  rep(i, 1, N+1) {
    cin >> p[i];
  }

  solve();

  double ans = 0.0;
  rep(j, 0, N+1) {
    if (j >= (N/2 + 1)) {
      ans += dp[N][j];
    }
  }

  Decimal(ans);
};
