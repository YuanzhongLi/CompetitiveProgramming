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
  int N;
  cin >> N;
  // a, b, c
  vector<vector<int>> dp(N+1, vector<int> (3, 0));
  // input a, b, c
  vector<vector<int>>  happy(N+1, vector<int> (3, 0));
  rep(i, 1, N+1) {
    cin >> happy[i][0] >> happy[i][1] >> happy[i][2];
  }

  rep(i, 1, N+1) {
    dp[i][0] = happy[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
    dp[i][1] = happy[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
    dp[i][2] = happy[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
  }

  cout << max(dp[N][0], max(dp[N][1], dp[N][2])) << endl;
};
