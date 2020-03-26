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

class state {
  public:
  int h, w, r, b;
  state() {}
  state(int h, int w, int r, int b): h(h), w(w), r(r), b(b) {}
  bool operator < (const state &st) const {
    if (h == st.h) {
      if (w == st.w) {
        if (r == st.r) {
          return b < st.b;
        } else {
          return r < st.r;
        }
      } else {
        return w < st.w;
      }
    } else {
      return h < st.h;
    }
  }
};

const int INF = 1e9+7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h, w;
  cin >> h >> w;
  vector<vector<PI>> grid(h, vector<PI> (w));
  int a;
  rep(i, 0, h) {
    rep(j, 0, w) {
      cin >> grid[i][j].first;
    }
  }
  rep(i, 0, h) {
    rep(j, 0, w) {
      cin >> grid[i][j].second;
    }
  }

  rep(i, 0, h) {
    rep(j, 0, w) {
      if (grid[i][j].first > grid[i][j].second) {
        swap(grid[i][j].first, grid[i][j].second);
      }
    }
  }

  vector<vector<PI>> dp(h, vector<PI> (w, PI {0, INF}));
  dp[h-1][w-1] = grid[h-1][w-1];

  for (int i = h-1; i >= 0; i--) {
    for (int j = w-1; j >= 0; j--) {
      if (i == h-1 && j == w-1) continue;
      { // down
        if (i < h - 1) {
          int dp_fi = dp[i+1][j].first;
          int dp_sec = dp[i+1][j].second;
          int g_fi = grid[i][j].first;
          int g_sec = grid[i][j].second;
          int diff = abs((dp_fi + g_sec) - (dp_sec + g_fi));
          int dp_diff = dp[i][j].second - dp[i][j].first;
          if (diff < dp_diff) {
            dp[i][j].first = dp_fi + g_sec;
            dp[i][j].second = dp_sec + g_fi;
            if (dp[i][j].first > dp[i][j].second) {
              swap(dp[i][j].first, dp[i][j].second);
            }
          }
        }
      }
      { // right
        if (j < w - 1) {
          int dp_fi = dp[i][j+1].first;
          int dp_sec = dp[i][j+1].second;
          int g_fi = grid[i][j].first;
          int g_sec = grid[i][j].second;
          int dp_diff = dp[i][j].second - dp[i][j].first;
          int diff = abs((dp_fi + g_sec) - (dp_sec + g_fi));
          if (diff < dp_diff) {
            dp[i][j].first = dp_fi + g_sec;
            dp[i][j].second = dp_sec + g_fi;
            if (dp[i][j].first > dp[i][j].second) {
              swap(dp[i][j].first, dp[i][j].second);
            }
          }
        }
      }
    }
  }

  cout << dp[0][0].second - dp[0][0].first << endl;

  return 0;
};
