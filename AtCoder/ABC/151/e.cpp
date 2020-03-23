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
#define deg_to_rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad_to_deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)

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

long long fact[100005], inv[100005], factinv[100005];
// initし忘れるな!!!
void init(int m) {
  fact[0] = 1;
  for(int i = 1; i < 100005; i++) {
    fact[i] = (1ll * fact[i - 1] * i) % m;
  }
  for(int i = 0; i < 100005; i++) {
    inv[i] = modinv(i, m);
    factinv[i] = modinv(fact[i], m);
  }
};

// nCrを計算する
long long comb(long long n, long long r) {
    return fact[n] * factinv[r] * factinv[n - r];
};

// nCr mod を計算する
long long modcomb(long long n, long long r, long long m) {
    return (fact[n] * factinv[r] % m) * factinv[n - r] % m;
};

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i, 0, N) {
    cin >> A[i];
  }

  sort(All(A));

  ll ans = 0;

  ll mod = (ll) 1e9+7;

  if (K == 1ll) {
    cout << 0 << endl;
    return 0;
  }

  init((int)1e9+7);

  ll max_s = 0ll, min_s = 0ll;

  rep(i, 0, N) {
    ll a = A[i];
    a = (a+mod) % mod;
    if (i+1 >= K) {
      max_s += (a * modcomb(i, K-1, mod));
      max_s %= mod;
    }
    if (N-i >= K) {
      min_s += (a * modcomb(N-i-1, K-1, mod));
      min_s %= mod;
    }
  }
  ans = (max_s - min_s + mod) % mod;
  cout << ans << endl;
};
