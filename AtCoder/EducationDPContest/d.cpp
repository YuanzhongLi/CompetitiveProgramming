#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define BiSearchRangeNum(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y)

int main() {
  int N, W;
  cin >> N >> W;
  vector<vector<ll>> dp(N+1, vector<ll> (W+1, 0));
  // w, v
  vector<pair<int, int>> items(N+1);
  rep(i, 1, N+1) {
    cin >> items[i].first >> items[i].second;
  }

  ll ans = 0;

  rep(i, 1, N+1) {
    rep(j, 0, W+1) {
      if (j+items[i].first <= W) {
        dp[i][j+items[i].first] = max(dp[i - 1][j+items[i].first], dp[i-1][j] + items[i].second);
      }
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
    }
  }

  rep(i, 1, W+1) {
    ans = max(ans, dp[N][i]);
  }

  cout << ans << endl;
};
