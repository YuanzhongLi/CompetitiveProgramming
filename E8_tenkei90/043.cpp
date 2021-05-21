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

class Dijkstra {
  ll INF = 1001002003004005006ll;
  int WHITE = 0; // 未到達
  int GRAY = 1; // 到達
  int BLACK = 2; // 探索済み
public:
  int V; // 頂点数
  // <node, cost>
  vector<vector<pair<int, ll>>> graph;
  vector<int> color;
  vector<ll> dist;
  vector<int> parent;

  Dijkstra(int v): V(v) {
    graph.resize(v);
    color.resize(v);
    dist.resize(v);
    parent.resize(v);
  }

  void add_edge(int from, int to, ll cost) {
    graph[from].pb(make_pair(to, cost));
  }

  void min_path(int s) {
    // <cost, node>
    priority_queue<pair<ll, int>> PQ;

    // 初期化
    for (int i = 0; i < V; i++) {
      dist[i] = INF;
      color[i] = 0;
    }

    dist[s] = 0;
    dist[s+V/2] = 0;
    PQ.push(make_pair(0ll, s));
    PQ.push(make_pair(0ll, s+V/2));
    color[s] = GRAY;
    color[s+V/2] = GRAY;

    while (!PQ.empty()) {
      auto f = PQ.top(); PQ.pop();
      int u = f.second;
      color[u] = BLACK;

      for (int j = 0; j < graph[u].size(); j++) {
        int v = graph[u][j].first;
        if (color[v] == BLACK) continue;
        if (dist[v] > dist[u] + graph[u][j].second) {
          dist[v] = dist[u] + graph[u][j].second;
          parent[v] = u; // 経路を求めるために親ノードを更新
          // priority_queueはデフォルトで大きい値を優先するため-1をかける
          PQ.push(make_pair(dist[v] * (-1ll), v));
          color[v] = GRAY;
        }
      }
    }
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int H, W; cin >> H >> W;
  int N = H*W;

  Dijkstra D(2*N);
  int rs, cs, rt, ct; cin >> rs >> cs >> rt >> ct;
  rs--; cs--; rt--; ct--;
  int s = rs * W + cs, e = rt * W + ct;
  vvch grid(H, vch(W)); rep(i,0,H) rep(j,0,W) cin >> grid[i][j];
  int dy[4] = {-1, 0, 1, 0}; // u, r, d, l
  int dx[4] = {0, 1, 0, -1};
  rep(u,0,N) {
    int uy = u/W, ux = u%W;
    if (grid[uy][ux] == '#') continue;
    rep(j,0,4) {
      int vy = uy + dy[j], vx = ux + dx[j];
      if (0 <= vy && vy < H && 0 <= vx && vx < W && grid[vy][vx] == '.') {
        int v = vy*W+vx;
        if (j&1) { // yoko
          D.add_edge(u, v, 0);
          D.add_edge(u+N, v, 1);
        } else { // tate
          D.add_edge(u+N, v+N, 0);
          D.add_edge(u, v+N, 1);
        }
      }
    }
  }

  D.min_path(s);
  cout << min(D.dist[e], D.dist[e+N]) << endl;

  return 0;
};
