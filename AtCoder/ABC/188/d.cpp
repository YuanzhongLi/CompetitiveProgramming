// #define LOCAL
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (ll)s; i < (ll)n; i++)
#define rrep(i,n,e) for (int i = (ll)n; i > (ll)e; i--)
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
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

constexpr ll LINF = 1001002003004005006ll;
constexpr int INF = 1002003004;
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

void LINE_OUT() {
  cout << "--------------" << endl;
};

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define LINE LINE_OUT();
#else
#define debug(...) 71
#define LINE 71;
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
  for (auto& vec : df) {
    print(vec);
  }
};

vl sum;

vi compress(int n, vi &X1, vi &X2, int s, int e, vl &C) {
  vector<int> xs;

  rep(i, 0, n) {
    for (int d = -1; d <= 1; d++) {
      int tx1 = X1[i]+d, tx2 = X2[i]+d;
      if (s <= tx1 && tx1 <= e) xs.pb(tx1);
      if (s <= tx2 && tx2 <= e) xs.pb(tx2);
    }
  }

  sort(All(xs));
  xs.erase(unique(All(xs)), xs.end());
  sum.resize(xs.size());
  rep(i, 0, n) {
    X1[i] = lbidx(xs, X1[i]);
    X2[i] = lbidx(xs, X2[i]);
    sum[X1[i]] += C[i];
    sum[X2[i]] -= C[i];
    // X1[i] = find(All(xs), X1[i]) - xs.begin();
    // X2[i] = find(All(xs), X2[i]) - xs.begin();
  }

  rep(i, 1, sum.size()) sum[i] += sum[i-1];

  return xs;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N, C_; cin >> N >> C_;
  int e = -INF, s = INF;
  vi A(N), B(N);
  vl C(N);
  rep(i, 0, N) {
    cin >> A[i] >> B[i] >> C[i];
    B[i]++;
    chmin(s, A[i]);
    chmax(e, B[i]);
  }

  auto xs = compress(N, A, B, s, e, C);
  debug(xs);
  debug(sum);

  ll ans = 0;
  rep(i, 0, xs.size()-1) {
    if (sum[i] > C_) {
      ans += C_*(xs[i+1]-xs[i]);
    } else {
      ans += sum[i]*(xs[i+1]-xs[i]);
    }
  }

  cout << ans << endl;

  return 0;
};
