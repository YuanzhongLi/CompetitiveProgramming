#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (ll)s; i < (ll)n; i++)
#define rrep(i,n,e) for (int i = (ll)n-1; i >= (ll)e; i--)
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define llbidx(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y) // 二要素間の距離
// #define M_PI 3.14159265358979323846 // CFでは定義しておく必要あり
#define deg2rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad2deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)
#define Find(set, element) set.find(element) != set.end()
#define Decimal(x) cout << fixed << setprecision(10) << x << endl; // 小数点を10桁まで表示
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << "\n";
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define endl "\n"
// gcj print用
#define Case(x) printf("Case #%d: ", x);

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

const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;

int POWINT(int x, int n) {
  int ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
};

ll POWLL(ll x, int n) {
  ll ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
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

void print() {
  cout << endl;
};

template <class T>
void print(vector<T> &vec) {
  for (auto& a : vec) {
    cout << a;
    if (&a != &vec.back()) cout << " ";
  }
  cout << endl;
};

template <class T>
void print(vector<T> &vec, ll k){
   ll n = vec.size();
   k = min(k, n);
   rep(i, 0, k-1) cout << vec[i] << " ";
   cout << vec[k-1] << endl;
};

template <class T>
void print(vector<vector<T>> &df) {
  for (auto& vec : df) {
    print(vec);
  }
};

template<class T, class U>
void print(pair<T,U> &p){
  cout << p.first << " " << p.second << "\n";
};

const ll MAX = 1e6+5;

// エラトステネスの篩
class Sieve {
public:
  ll n;
  vl f, primes;
  Sieve() {}
  Sieve(ll n = 1): n(n), f(n+1) {
    f[0] = f[1] = -1ll;
    for (ll i = 2; i <= n; i++) {
      if (f[i]) continue;
      primes.pb(i);
      f[i] = i;
      for (ll j = i*i; j <= n; j += i) {
        if (!f[j]) f[j] = i; // jの最小の素因数
      }
    }
  }

  bool isPrime(int x) { return f[x] == x; }

  // 素因数分解 (x > MAXの時MAX*MAXまで求められるO(1~MAXまでの素数の数))
  vl factorList(ll x) {
    if (x > MAX) {
      vl res;
      int idx = 0;
      while (x > 1) {
        ll p = primes[idx];
        if (x % p == 0) {
          x /= p;
          res.pb(p);
        } else {
          idx++;
        }
        if (idx >= (int)primes.size()) break;
      }

      if (x > 1) res.pb(x);
      return res;
    } else {
      vl res;
      while (x != 1ll) {
        res.pb(f[x]);
        x /= f[x];
      }
      return res;
    }
  }

  vpl factor(ll x) {
    vl fl = factorList(x);
    if (fl.size() == 0) return {};

    vpl res(1, PLL(fl[0], 0));

    for (int p: fl) {
      if (res.back().first == p) {
        res.back().second++;
      } else {
        res.emplace_back(p, 1);
      }
    }

    return res;
  }
};

vl table(12);
void init_table() {
  table[0] = 0;
  table[1] = 1;
  rep(i, 2, 12) {
    table[i] = i + table[i-1];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N; cin >> N;

  Sieve si(MAX);
  init_table();

  auto factor = si.factor(N);
  ll ans = 0;

  for (auto pi: factor) {
    ll num = pi.second;
    rep(i, 1, 12) {
      if (table[i] <= num && num < table[i+1]) {
        ans += i;
        break;
      }
    }
  }

  cout << ans << endl;

  return 0;
};
