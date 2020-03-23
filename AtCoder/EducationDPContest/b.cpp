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

#define INF 1e9

int main() {
  int N, K;
  cin >> N >> K;
  // height, cost
  vector<vector<int>> dp (N + K - 1, vector<int>(2, 0));
  rep(i, 0, K - 1) {
    dp[i][0] = INF;
  }
  rep(i, K - 1, N + K - 1) {
    cin >> dp[i][0];
  }
  rep(i, K, N + K - 1) {
    int m = INF;
    rep(j, 1, K + 1) {
      m = min(m, abs(dp[i - j][0] - dp[i][0]) + dp[i - j][1]);
    }
    dp[i][1] = m;
  }

  cout << dp[N + K - 2][1] << endl;
};
