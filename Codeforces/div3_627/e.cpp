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
static const int MAX_H = 2000;
static const int MAX_N = 2000;
int dp[MAX_N+5][MAX_H+5];

void init() {
  rep(i, 0, MAX_N+5) {
    rep(j, 0, MAX_H+5) {
      dp[i][j] = -1;
    }
  }
};

int main() {
  int n, h, l, r;
  cin >> n >> h >> l >> r;

  init();

  vector<int> A(n+1);
  rep(i, 1, n+1) {
    cin >> A[i];
  }

  dp[0][0] = 0;
  rep(i, 1, n+1) {
    int a = A[i];
    rep(j, 0, h) {
      { // a
        if (dp[i-1][j] != -1) {
          int time = (a+j) % h;
          if (l <= time && time <= r) {
            dp[i][time] = max(dp[i-1][j] + 1, dp[i][time]);
          } else {
            dp[i][time] = max(dp[i-1][j], dp[i][time]);
          }
        }
      }
      { // a-1
        if (dp[i-1][j] != -1) {
          int time = (a+j-1+h) % h;
          if (l <= time && time <= r) {
            dp[i][time] = max(dp[i-1][j] + 1, dp[i][time]);
          } else {
            dp[i][time] = max(dp[i-1][j], dp[i][time]);
          }
        }
      }
    }
  }
  int ans = 0;

  rep(i, 0, n+5) {
    rep(j, 0, h+2) {
      // cout << dp[i][j];
      ans = max(ans, dp[i][j]);
    }
  }

  cout << ans << endl;
};
