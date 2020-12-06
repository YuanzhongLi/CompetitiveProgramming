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

int f(int n, int id, vvvi &row, vvvi &col, vvi &grid, int c_mi, int c_ma, int r_mi, int r_ma) {
  int y = id/n, x = id%n;
  int num = grid[y][x];

  int lat = max(abs(n-1-x), x);
  int lon = max(abs(n-1-y), y);

  int ret = 0;
  if (!(c_mi == INF || c_mi == -INF)) {
    chmax(ret, lat * abs(c_mi-y));
  }
  if (!(c_ma == INF || c_ma == -INF)) {
    chmax(ret, lat * abs(c_ma-y));
  }

  if (!(r_mi == INF || r_mi == -INF)) {
    chmax(ret, abs(r_mi-x) * lon);
  }
  if (!(r_ma == INF || r_ma == -INF)) {
    chmax(ret, abs(r_ma-x) * lon);
  }

  return ret;
};

void solve() {
  int n; cin >> n;
  vvch grid_tmp(n, vch(n));
  rep(i, 0, n) rep(j, 0, n) cin >> grid_tmp[i][j];
  vvi grid(n, vi(n));
  vi cnt(10, 0);
  rep(i, 0, n) rep(j, 0, n) {
    grid[i][j] = (int)grid_tmp[i][j]-'0';
    cnt[grid[i][j]]++;
  }

  vvvi row(10, vvi(n, vi(2, 0))), col(10, vvi(n, vi(2, 0)));
  rep(i, 0, 10) {
    rep(j, 0, n) {
      row[i][j][0] = INF;
      row[i][j][1] = -INF;
      col[i][j][0] = INF;
      col[i][j][1] = -INF;
    }
  }
  rep(i, 0, n) {
    rep(j, 0, n) {
      int num = grid[i][j];
      chmin(row[num][i][0], j);
      chmax(row[num][i][1], j);
      chmin(col[num][j][0], i);
      chmax(col[num][j][1], i);
    }
  }

  vi c_mis(10, INF), c_mas(10, -INF), r_mis(10, INF), r_mas(10, -INF);
  rep(i, 0, n) {
    rep(j, 0, 10) {
      chmin(c_mis[j], col[j][i][0]);
      chmax(c_mas[j], col[j][i][1]);
      chmin(r_mis[j], row[j][i][0]);
      chmax(r_mas[j], row[j][i][1]);
    }
  }

  vi ans(10, 0);
  rep(i, 0, n) {
    rep(j, 0, n) {
      int id = i*n+j;
      int num = grid[i][j];
      if (cnt[num] < 2) continue;
      int c_mi = c_mis[num], c_ma = c_mas[num], r_mi = r_mis[num], r_ma = r_mas[num];
      chmax(ans[num], f(n, id, row, col, grid, c_mi, c_ma, r_mi, r_ma));
    }
  }

  rep(i, 0, 10) {
    cout << ans[i];
    if (i < 9) cout << " ";
  }
  cout << endl;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
};
