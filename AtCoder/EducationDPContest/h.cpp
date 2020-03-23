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

static const int mod = 1e9+7;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int>> grid(H, vector<int> (W));
  char ch;
  rep(i, 0, H) {
    rep(j, 0, W) {
      cin >> ch;
      if (ch == '.') {
        grid[i][j] = 1;
      } else {
        grid[i][j] = 0;
      }
    }
  }

  vector<vector<int>> dp(H, vector<int> (W, 0));
  dp[0][0] = 1;

  rep(h, 0, H) {
    rep(w, 0, W) {
      if (grid[h][w] == 0) continue; // 壁
      // left
      if (w > 0) {
        if (grid[h][w-1] == 1) {
          dp[h][w] += dp[h][w-1];
          dp[h][w] %= mod;
        }
      }

      // up
      if (h > 0) {
        if (grid[h-1][w] == 1) {
          dp[h][w] += dp[h-1][w];
          dp[h][w] %= mod;
        }
      }
    }
  }

  cout << dp[H-1][W-1] << endl;
};
