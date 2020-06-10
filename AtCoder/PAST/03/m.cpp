#define LOCAL
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
#define llbidx(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y) // dist between two elements
// #define M_PI 3.14159265358979323846 // CF
#define deg2rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad2deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)
#define Find(set, element) set.find(element) != set.end()
#define Decimal(x) cout << fixed << setprecision(10) << x << endl; // 小数点を10桁まで表示
#define endl "\n"
#define Case(x) printf("Case #%d: ", x); // gcj

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<PI> vpi;
typedef vector<vector<PI>> vvpi;
typedef vector<PLL> vpl;
typedef vector<vector<PLL>> vvpl;
typedef vector<char> vch;
typedef vector<vector<char>> vvch;

constexpr ll LINF = 1001002003004005006ll;
constexpr int INF = 1001001001;
constexpr int n_max = 2e5+10;

template<class T>
inline bool chmax(T &a, T b) { if(a < b) { a = b; return true; } return false; };
template<class T>
inline bool chmin(T &a, T b) { if(a > b) { a = b; return true; } return false; };

template<class T, class U>
T POW(T x, U n) {T ret = 1; while (n > 0) {if (n & 1) {ret *= x;} x *= x; n >>= 1;} return ret;};

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

void Print() { cout << endl; };
template <class T>
void Print(vector<T> &vec) {
  for (auto& a : vec) {cout << a; if (&a != &vec.back()) cout << " ";}
  cout << endl;
};
template <class T>
void Print(vector<T> &vec, ll k){
   ll n = vec.size();
   k = min(k, n);
   rep(i, 0, k-1) cout << vec[i] << " ";
   cout << vec[k-1] << endl;
};
template <class T>
void Print(vector<vector<T>> &df) {for (auto& vec : df) {print(vec);}};
template<class T, class U>
void Print(pair<T,U> &p){cout << p.first << " " << p.second << endl;};

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define print(...) Print(__VA_ARGS__)
#else
#define debug(...) 71
#define print(...) 71
#endif

const int N_MAX = 100005;
vvi graph(N_MAX);

vi f(int s) {
  vi dist(N_MAX, INF);
  vector<bool> visited(N_MAX, false);
  vi par(N_MAX, -1);

  queue<int> q;
  q.push(s);
  dist[s] = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (visited[u]) continue;
    visited[u] = true;

    for (int v: graph[u]) {
      if (visited[v] || v == par[u]) continue;
      chmin(dist[v], dist[u]+1);
      q.push(v);
    }
  }

  return dist;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M; cin >> N >> M;
  rep(i, 0, M) {
    int u, v; cin >> u >> v; u--; v--;
    graph[u].pb(v);
    graph[v].pb(u);
  }

  int s; cin >> s; s--;
  int K; cin >> K;
  map<int, int> table; table[s] = 0;
  vi T; T.pb(s);
  rep(i, 0, K) {
    int t; cin >> t; t--; T.pb(t);
    table[t] = i+1;
  }

  vvi graph2(K+1, vi(K+1, INF));
  rep(i, 0, K+1) graph2[i][i] = 0;

  rep(i, 0, K+1) {
    auto dist = f(T[i]);
    rep(j, 0, K+1) {
      graph2[i][table[T[j]]] = dist[T[j]];
      graph2[table[T[j]]][i] = dist[T[j]];
    }
  }

  rep(k, 0, K+1) {
    rep(i, 0, K+1) {
      rep(j, 0, K+1) {
        chmin(graph2[i][j], graph2[i][k]+graph2[k][j]);
      }
    }
  }

  int V = K+1;
  vvi dp(1 << V, vi(V, INF));
  rep(i, 1, V) {
    dp[(1<<V)-1][i] = 0;
  }

  for (int S = (1 << V)-2; S >= 1; S--) {
    rep(v, 0, V) {
      rep(u, 0, V) {
        if (!((S >> u)&1)) {
          chmin(dp[S][v], dp[S | 1 << u][u]+graph2[v][u]);
        }
      }
    }
  }

  cout << dp[1][0] << endl;
  return 0;
};
