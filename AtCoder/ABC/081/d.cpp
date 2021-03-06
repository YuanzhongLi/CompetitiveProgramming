#define LOCAL
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

vpi pos_f(vi A, int N) {
  vpi ret;
  int ma = -INF;
  int ma_idx = -1;
  rep(i,0,N) {
    if (chmax(ma, A[i])) ma_idx = i;
  }
  rep(i, 1, N) {
    if (A[i] < A[i-1]) {
      ret.pb({ma_idx, i});
      A[i] += ma;
      ma = A[i];
      ma_idx = i;
    }
  }
  return ret;
};

vpi neg_f(vi A, int N) {
  vpi ret;
  int mi = INF;
  int mi_idx = -1;
  rep(i,0,N) {
    if (chmin(mi, A[i])) mi_idx = i;
  }
  for (int i = N-2; i >= 0; i--) {
    if (A[i] > A[i+1]) {
      ret.pb({mi_idx, i});
      A[i] += mi;
      mi = A[i];
      mi_idx = i;
    }
  }
  return ret;
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N; cin >> N;
  vi A(N);
  int ma = -INF, mi = INF, ma_idx = -1, mi_idx = -1;

  rep(i,0,N) {
    cin >> A[i];
    if (chmax(ma, A[i])) ma_idx = i;
    if (chmin(mi, A[i])) mi_idx = i;
  }

  vpi ans;
  if (ma < 0) {
    ans = neg_f(A, N);
  } else if (mi >= 0) {
    ans = pos_f(A, N);
  } else {
    if (abs(ma) >= abs(mi)) {
      rep(i,0,N) {
        if (i == ma_idx) continue;
        ans.pb({ma_idx, i});
        A[i] += ma;
      }
      vpi tmp = pos_f(A, N);
      for (auto pi: tmp) ans.pb(pi);
    } else {
      rep(i,0,N) {
        if (i == mi_idx) continue;
        ans.pb({mi_idx, i});
        A[i] += mi;
      }
      vpi tmp = neg_f(A, N);
      for (auto pi: tmp) ans.pb(pi);
    }
  }

  int M = ans.size();
  cout << M << endl;
  rep(i,0,M) cout << ans[i].first+1 << " " << ans[i].second+1 << endl;

  return 0;
};
