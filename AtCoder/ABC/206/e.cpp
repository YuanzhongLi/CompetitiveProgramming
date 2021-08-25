// #define LOCAL
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,s,n) for (int i = (ll)s; i < (ll)n; i++)
#define rrep(i,n,e) for (int i = (ll)n; i > (ll)e; i--)
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
// #define M_PI 3.14159265358979323846 // CF
#define deg2rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad2deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)
#define Find(set, element) set.find(element) != set.end()
#define Decimal(x) cout << fixed << setprecision(10) << x << endl; // print Decimal number 10 Rank
#define endl "\n"
#define Case(x) printf("Case #%d: ", x); // gcj

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
typedef vector<PI> vpi;
typedef vector<vector<PI>> vvpi;
typedef vector<PLL> vpl;
typedef vector<vector<PLL>> vvpl;
typedef vector<char> vch;
typedef vector<vector<char>> vvch;

constexpr ll INF = 1001002003004005006ll;
constexpr int n_max = 2e5+10;

template<class T>
inline bool chmax(T &a, T b) { if(a<b) { a=b; return true; } return false; };
template<class T>
inline bool chmin(T &a, T b) { if(a>b) { a=b; return true; } return false; };

template<class T, class U>
T POW(T x, U n) {T ret=1; while (n>0) {if (n&1) {ret*=x;} x*=x; n>>=1;} return ret;};

// debug
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) {return '"' + s + '"';};
string to_string(const char c) {return to_string((string) &c);};
string to_string(bool b) {return (b ? "true" : "false");};
// string to_string(mint m) {return to_string(m.a); };
template <size_t N>
string to_string(bitset<N> v){
  string res = "";
  for(size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
  return res;
};
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for(const auto &x : v) {
    if(!first) res += ", ";
    first = false; res += to_string(x);
  }
  res += "}";
  return res;
};
template <typename A, typename B>
string to_string(pair<A, B> p){return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}

void debug_out() {cerr << endl;};
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); };

void LINE_OUT() { cout << "--------------" << endl; };
void SPACE_OUT() { cout << endl; };

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define LINE LINE_OUT();
#define SPACE SPACE_OUT();
#else
#define debug(...) 71
#define LINE 71;
#define SPACE 71;
#endif

void print() { cout << endl; }
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(tail) != 0) cout << " ";
  print(forward<Tail>(tail)...);
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
void print(vector<vector<T>> &df) {
  for (auto& vec : df) { print(vec); }
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

int f(vi ps, int l, int r) {
  int n = ps.size();
  int ret = 0;
  rep(i,0,1<<n) {
    int cnt = 0;
    int tmp = 1;
    rep(j,0,n) {
      if ((i>>j)&1) {
        cnt++;
        tmp *= ps[j];
      }
    }
    int val1 = (l-1)/tmp, val2 = r/tmp;
    if (cnt&1) ret -= (val2-val1);
    else ret += (val2 -val1);
  }
  return ret;
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  Sieve si(MAX);
  int L, R; cin >> L >> R;
  function<int(int,int)> g1 = [&](int l, int r) {
    int ret = 0;
    rep(x, l, r+1) {
      if (x == 1) {
        ret += r-l+1;
      } else {
        auto fa = si.factor(x);
        vi ps;
        for (auto pi: fa) ps.pb(pi.first);
        ret += f(ps, l, r);
      }
    }
    return ret;
  };

  function<int(int,int)> gx = [&](int l, int r) { // = gy
    int ret = 0;
    rep(x, l, r+1) {
      int val1 = (l-1)/x, val2 = r/x;
      ret += (val2-val1);
    }
    return ret;
  };

  function<int(int,int)> g1_gx = [&](int l, int r) { // = g1_gy
    int ret = 0;
    if (l == 1) ret = r;
    return ret;
  };

  function<int(int,int)> gx_gy = [&](int l, int r)  {
    return r-l+1;
  };

  function<int(int,int)> g1_gx_gy = [&](int l, int r) {
    if (l == 1) return 1;
    else return 0;
  };

  int val1 = g1(L, R) + gx(L, R) + gx(L, R) - g1_gx(L, R) - g1_gx(L,R) - gx_gy(L, R) + g1_gx_gy(L, R);
  int val2 = (R-L+1)*(R-L+1);

  cout << val2 - val1 << endl;

  return 0;
};
