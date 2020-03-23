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

const int INF = 1e9+7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int H, W;
  cin >> H >> W;

  vector<vector<char>> grid(H, vector<char> (W));
  rep(i, 0, H) {
    rep(j, 0, W) {
      cin >> grid[i][j];
    }
  }

  vector<vector<int>> dp(H, vector<int> (W, INF));
  dp[H-1][W-1] = 0;
  for (int r = H-1; r >= 0; r--) {
    for (int c = W-1; c >= 0; c--) {
      char ch = grid[r][c];
      { // up
        if (r > 0) {
          if (ch == '#' && grid[r-1][c] == '.') {
            dp[r-1][c] = min(dp[r-1][c], dp[r][c] + 1);
          } else {
            dp[r-1][c] = min(dp[r-1][c], dp[r][c]);
          }
        }
      }
      { // left
        if (c > 0) {
          if (ch == '#' && grid[r][c-1] == '.') {
            dp[r][c-1] = min(dp[r][c-1], dp[r][c] + 1);
          } else {
            dp[r][c-1] = min(dp[r][c-1], dp[r][c]);
          }
        }
      }
    }
  }

  if (grid[0][0] == '.') {
    cout << dp[0][0] << endl;
  } else {
    cout << dp[0][0] + 1 << endl;
  }

  return 0;
};
