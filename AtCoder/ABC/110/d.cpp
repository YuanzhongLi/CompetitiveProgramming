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
#define Decimal(x) printf("%.10f\n", x) // 小数点を10桁まで表示
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;

int POWINT(int x, int n) {
  int ret = 1;
  rep(i, 0, n) ret *= x;
  return ret;
};

ll POWLL(int x, int n) {
  ll ret = 1;
  rep(i, 0, n) ret *= x;
  return ret;
};

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

vector<int> divisor(int n) {
  vector<int> ret;
  for(int i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  // sort(All(ret));
  return (ret);
};

int isPrime(int x) {
  int i;
  if (x < 2) return 0;
  else if (x == 2) return 1;

  if (x % 2 == 0) return 0;
  for (i = 3; i*i <= x; i += 2) {
    if (x % i == 0) return 0;
  }
  return 1;
};

// 素因数分解
// pn = { 2, 3, 5, 7 ..} 可能性のある素数列
map<int, int> PrimeFactorization(int x, vector<int> &pn) {
  map<int, int> ret;
  rep(i, 0, pn.size()) {
    ret.emplace(pn[i], 0);
  }

  int pn_idx = 0;
  while(x > 1) {
    int p = pn[pn_idx];
    if (x % p == 0) {
      x /= p;
      ret[p]++;
    } else {
      pn_idx++;
    }
  }

  return ret;
};

// x^n mod Mを計算する
// 引き算は引かられる数にmodを足す!
long long modpow(long long x, long long n, long long M) {
  long long res = 1;
  if (n > 0) {
    res = modpow(x, n / 2, M);
    if (n % 2 == 0) res = (res * res) % M;
    else res = (((res * res) % M) * x) % M;
  }
  return res;
};

// initし忘れるな!!!
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

long long fact[200005], inv[200005], factinv[200005];

void init(ll m) {
  fact[0] = 1;
  for(int i = 1; i < 200000; i++) {
    fact[i] = (1ll * fact[i - 1] * i) % m;
  }
  for(int i = 0; i < 200000; i++) {
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

static const ll mod = 1000000007;

int main() {
  int N, M;
  cin >> N >> M;

  if (N == 1 || M == 1) {
    cout << 1 << endl;
    return 0;
  }

  init(mod);

  auto di = divisor(M);
  vector<int> pn;
  for (auto n: di) {
    if (isPrime(n)) {
      pn.pb(n);
    }
  }

  sort(All(pn));

  auto m = PrimeFactorization(M, pn);


  ll ans = 1ll;
  for (int p: pn) {
    int n = m[p];
    ans *= modcomb((ll) (n+N-1), (ll) n, mod);
    ans %= mod;
  }

  cout << ans << endl;
};
