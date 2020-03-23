#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back

int mod = 1e9+7;

ll dp[105][4][4][4];

void solve () {
  dp[0][3][3][3] = 1;
  rep(idx, 1, 105) {
    rep (i, 0, 4) {
      rep(j, 0, 4) {
        rep(k, 0, 4) {
          rep(l, 0, 4) {
            if (i == 0 && k == 2 && l == 1) continue;
            if (i == 0 && j == 2 && l == 1) continue;
            if (i == 0 && j == 1 && k == 2) continue;
            if (j == 0 && k == 1 && l == 2) continue;
            if (i == 2 && j == 0 && k == 1) continue;
            if (j == 2 && k == 0 && l == 1) continue;
            if (i == 0 && j == 2 && k == 1) continue;
            if (j == 0 && k == 2 && l == 1) continue;
            dp[idx][j][k][l] += (dp[idx - 1][i][j][k] % mod);
          }
        }
      }
    }
  }
};

int main() {
  int N;
  cin >> N;
  solve();

  ll ans = 0;
  rep(i, 0, 4) {
    rep(j, 0, 4) {
      rep(k, 0, 4) {
        ans += dp[N][i][j][k];
        ans = ans % mod;
      }
    }
  }
  cout << ans << endl;
};
