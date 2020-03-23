#include <bits/stdc++.h>
using namespace std;

const static int Null = -1;

const static int mod = 1e9+7;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n + 1, 0);

  vector<int> dp(n + 1, 0);

  for (int i = 1; i <= m; i++) {
    int b;
    cin >> b;
    a[b] = -1;
  }

  bool flag = true;

  if (a[1] == -1) {
    dp[1] = Null;
  } else dp[1] = 1;
  if (a[2] == -1 && a[1] == -1) {
    cout << 0 << endl;
    return 0;
  } else if (a[2] != -1 && a[1] == -1) {
    dp[2] = 1;
  } else if (a[2] == -1 && a[1] != -1) {
    a[2] = Null;
  } else if (a[2] != -1 && a[1] != -1) {
    dp[2] = 2;
  }



  for (int i = 3; i <= n; i++) {
    if (a[i] == -1) {
      dp[i] = Null;
    } else {
      if (dp[i - 1] != Null && dp[i - 2] != Null) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
      } else if (dp[i - 1] == Null && dp[i - 2] != Null) {
        dp[i] = dp[i - 2] % mod;
      } else if (dp[i - 1] != Null && dp[i - 2] == Null) {
        dp[i] = dp[i - 1] % mod;
      } else if (dp[i - 1] != Null && dp[i - 2] != Null) {
        flag = false;
        break;
      }
    }
  }

  if (!flag) {
    cout << 0 << endl;
    return 0;
  }

  cout << dp[n] << endl;

};
