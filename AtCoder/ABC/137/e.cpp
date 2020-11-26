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

// 単一始点全点間最短路を求めるアルゴリズム。単一始点全点間最短路を求めるアルゴリズム。負辺があっても動作する。また負閉路も検出する。

// 計算量 O(V * E)

struct Edge {
  int from;
  int to;
  int cost;
};

vector<int> bellman_ford(int s, int V, vector<Edge> &edges) {
  vector<int> dist(V, INF);
  dist[s] = 0;
  rep(i, 0, V - 1) {
    rep(j, 0, edges.size()) {
      struct Edge e = edges[j];
      if (dist[e.from] == INF) continue;
      dist[e.to] = min(dist[e.to], dist[e.from] + e.cost);
    }
  }

  bool flag = true;
  rep(i, 0, edges.size()) {
    struct Edge e = edges[i];
    if (dist[e.from] == INF) continue;
    // 負回路発見
    if (dist[e.from] + e.cost < dist[e.to]) {
      flag = false;
      break;
    }
  }

  if (flag) {
    return dist;
  } else {
    vector<int> neg;
    return neg;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M, P; cin >> N >> M >> P;
  int s = 0, e = N-1;
  vvpi graph(N), rev_graph(N);
  rep(i, 0, M) {
    int a, b, c; cin >> a >> b >> c;
    a--; b--;
    graph[a].pb(make_pair(b, c));
    rev_graph[b].pb(make_pair(a, c));
  }

  vector<bool> from_s(N, false), to_e(N, false);
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (from_s[u]) continue;
    from_s[u] = true;

    for (auto p: graph[u]) {
      int v = p.first;
      if (from_s[v]) continue;
      q.push(v);
    }
  }

  q.push(e);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (to_e[u]) continue;
    to_e[u] = true;

    for (auto p: rev_graph[u]) {
      int v = p.first;
      if (to_e[v]) continue;
      q.push(v);
    }
  }

  vector<Edge> edges, rev_edges;

  rep(i, 0, N) {
    for (auto p: graph[i]) {
      int a = i;
      int b = p.first;
      int c = p.second;
      if (from_s[a] && to_e[b]) {
        edges.pb({a, b, -(c-P)});
        rev_edges.pb({b, a, -(c-P)});
      }
    }
  }

  auto dist_s = bellman_ford(s, N, edges);
  auto dist_e = bellman_ford(e, N, edges);
  auto dist_rev_e = bellman_ford(e, N, rev_edges);

  if (dist_s.empty()) {
    cout << -1 << endl;
  } else {
    int ans = 0;
    int s2e = -dist_s[e];
    rep(i, 0, N) {
      chmax(ans, s2e-dist_e[i]-dist_rev_e[i]);
    }

    cout << ans << endl;
  }

  return 0;
};
