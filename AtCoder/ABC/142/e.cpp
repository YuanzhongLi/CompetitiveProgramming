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

static const int INF = 1001001001;

int main() {
  int n, m;
  cin >> n >> m;
  vector<PI> key;
  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;
    int s = 0; // s: 集合
    rep(j, 0, b) {
      int c;
      cin >> c;
      --c;
      s |= 1 << c;
    }
    key.eb(s, a);
  }

  vector<int> dp(1 << n, INF); // 2^n
  dp[0] = 0;
  rep(s, 0, 1 << n) {
    rep(i, 0, m) {
      int t = s | key[i].first; // 遷移先
      int cost = dp[s] + key[i].second;
      dp[t] = min(dp[t], cost);
    }
  }

  int ans = dp.back();
  if (ans == INF) ans = -1;
  cout << ans << endl;

  return 0;
};
