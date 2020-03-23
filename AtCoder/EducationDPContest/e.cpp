#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define BiSearchRangeNum(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y)turn idx;

int main() {
  int N, W;
  cin >> N >> W;
  vector<ll> w(N), v(N);
  vector<ll> dp(100001, 1e18);
  rep(i, 0, N) {
    cin >> w[i] >> v[i];
  }
  dp[0] = 0;

  rep(i, 0, N) {
    for (int j = 100000; j >= 0; j--) {
      if (j >= v[i]) {
        dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
      }
    }
  }

  for (int j = 100000; j >= 0; j--) {
    if (dp[j] <= W) {
      cout << j << endl;
      return 0;
    }
  }

  return 0;
};
