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

const ll MAX = 50+5;

// エラトステネスの篩
struct Sieve {
  ll n;
  vl f, primes;
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

  // 素因数分解
  vl factorList(ll x) {
    vl res;
    while (x != 1ll) {
      res.pb(f[x]);
      x /= f[x];
    }
    return res;
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

Sieve si(MAX);

ll comb(ll n, ll r) {
  r = min<ll>(r, n-r);
  ll ret = 1;
  vl tmp(51, 0);
  rep(i, n-r+1, n+1) {
    auto f = si.factor(i);
    for (auto pi: f) {
      tmp[pi.first] += pi.second;
    }
  }
  rep(i, 1, r+1) {
    auto f = si.factor(i);
    for (auto pi: f) {
      tmp[pi.first] -= pi.second;
    }
  }
  rep(i, 1, 51) {
    ret *= POWLL(i, tmp[i]);
  }
  return ret;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N, A, B; cin >> N >> A >> B;
  vl V(N);
  rep(i, 0, N) {
    cin >> V[i];
  }
  sort(All(V));
  reverse(All(V));

  ll tot = 0;
  for (ll i = 0; i < A; i++) {
    tot += V[i];
  }

  double avg = (double)tot/(double)A;

  ll l, r;
  rep(i, 0, N) {
    if (V[i] == V[A-1]) {
      l = i;
      break;
    }
  }

  rrep(i, N, 0) {
    if (V[i] == V[A-1]) {
      r = i;
      break;
    }
  }

  ll a_num = r-l+1;
  ll aa_num = A-1-l+1;
  Decimal(avg);
  ll ans = 0;
  if (V[0] == V[A-1]) {
    rep(i, A, B+1) {
      if (i > a_num) break;
      ans += comb(a_num, i);
    }
  } else {
    ans = comb(a_num, aa_num);
  }

  cout << ans << endl;

  return 0;
};
