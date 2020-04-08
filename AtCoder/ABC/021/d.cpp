#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define ld long double
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
#define debug(x) cerr << #x << ": " << (x) << "\n";

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<int>>> vvvl;
typedef vector<PI> vpi;
typedef vector<vector<PI>> vvpi;
typedef vector<vector<vector<PI>>> vvvpi;
typedef vector<PLL> vpl;
typedef vector<vector<PLL>> vvpl;
typedef vector<vector<vector<PLL>>> vvvpl;

int POWINT(int x, int n) {
  int ret = 1;
  rep(i, 0, n) ret *= x;
  return ret;
};

ll POWLL(ll x, int n) {
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

const ll mod = 1e9+7;

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n, k;
  cin >> n >> k;

  init(mod);

  ll ans = 0ll;
  for (ll i = 0ll; i < min(k, n); i++) {
    ans += (modcomb(k-1ll, i, mod) * modcomb(n, i+1ll, mod));
    ans %= mod;
  }

  cout << ans << endl;

  return 0;
};
