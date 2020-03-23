#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long

int mod = 1e9+7;

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
};

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> ans(K);
  int R = N - K;
  if (R == 0) {
    rep(i, 0, K) {
      if (i == 0) cout << 1 << endl;
      else cout << 0 << endl;
    }
    return 0;
  } else {
    rep(i, 0, K) {
      int I = i + 1;
      if (R < I - 1) {
        cout << 0 << endl;
        continue;
      }
      ll ans = 1;
      rep(j, K - I + 1, K) {
        ans *= j;
        ans = (ans % mod);
      }
      rep(j, 1, I) {
        ans = ans * modinv(j, mod) % mod;
      }
      rep(j, I + 1, R + 2) {
        ans *= j;
        ans = (ans % mod);
      }
      rep(j, 1, R - I + 2) {
        ans = ans * modinv(j, mod) % mod;
      }
      cout << ans << endl;
    }
  }
};
