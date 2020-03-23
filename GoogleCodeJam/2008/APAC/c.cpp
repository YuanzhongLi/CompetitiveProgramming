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
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;

int POWINT(int x, int n) {
  int ret = 1;
  rep(i, 0, n) ret *= x;
  return ret;
};

ll POWLL(int x, int n) {
  ll ret = 1;
  rep(i, 0, n) ret *= x;
  return ret;
};

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

const int target = 1000000;

double solve(int M, double P, int X) {
  if (X >= target) return 1.0;
  int n = (1 << M);

  int cur_i = (ll) X * n / target; // 現在の段階
  if (cur_i == 0) return 0.0;

  if (M == 1) {
    if (cur_i == 1) {
      return P;
    } else {
      return 0.0;
    }
  }

  double ret = 0.0;

  int nxt_i = (ll) X * (1 << M - 1) / target; // 次の状態での段階

  rep(j, nxt_i, n+1) { // 勝って次の状態でjの段階に移る
    double tmp;
    if (j == nxt_i) {
      tmp = solve(M-1, P, X);
    } else {
      int bet =
    }

    ret = max(ret, tmp);
  }

  return ret;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  int M;
  double P;
  int X;
  rep(t, 0, N) {
    cin >> M >> P >> X;
    double ans = solve(M, P, X);
    printf("Case #%d: %.10f\n", t+1, ans);
  }

  return 0;
};
