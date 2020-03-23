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

static const ll mod = 1e9+7;
ll fact[200005], inv[200005], factinv[200005];

// a^n mod を計算する
long long modpow(long long a, long long n, long long m) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return res;
};

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
};

void init() {
  fact[0] = 1;
  rep(i, 1, 200000) {
    fact[i] = (1ll * fact[i - 1] * i) % mod;
  }
  rep(i, 0, 200000) {
    inv[i] = modinv(i, mod);
    factinv[i] = modinv(fact[i], mod);
  }
};

// nCr
ll modcomb(ll n, ll r, ll m) {
  // n! * inv(r!) * inv((n - r)!) % mod
  return (fact[n] * factinv[r] % m) * factinv[n - r] % m;
};

int main() {
  init();
  ll N, a, b, c;
  cin >> N >> a >> b >> c;
  ll A = a * modinv(a + b, mod) % mod;
  ll B = b * modinv(a + b, mod) % mod;
  ll AN = modpow(A, N, mod);
  ll BN = modpow(B, N, mod);
  ll r = 0;
  for (ll M = N; M < 2 * N; M++) {
    ll tmp = (AN * modpow(B, M - N, mod) % mod + BN * modpow(A, M - N, mod) % mod) % mod;
    tmp = tmp * modcomb(M - 1, N - 1, mod) % mod;
    tmp = tmp * M % mod;
    tmp = tmp * 100 % mod;
    tmp = tmp * modinv(a + b, mod) % mod;
    r = (r + tmp) % mod;
  };
  cout << r << endl;
};
