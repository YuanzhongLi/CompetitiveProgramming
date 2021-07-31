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

// <to, dist>
vector<pair<int, int>> G[200005];
class LCA {
public:
  int V, logV; // V: node num
  vector<int> depth, dist;
  vector<vector<int>> parent; // parent[k][v], go back 2^k

  LCA(int V) {
    this->V = V;
    logV = 0;
    while (V > (1LL<<logV)) logV++;
    this->depth = vector<int>(V);
    this->dist = vector<int>(V);
    this->parent = vector<vector<int>>(logV, vector<int>(V));
  }

  void init(int v, int par, int d, int l) { // dfs: calculate dist and parent
    depth[v] = d;
    parent[0][v] = par;
    dist[v] = l;
    for (int i = 0; i < (int)G[v].size(); i++) {
      int w = G[v][i].first;
      int lc = G[v][i].second;
      if (w == par) continue;
      init(w, v, d+1, lc + l);
    }
  }

  void build() { // doubling: build parent
    for (int k = 0; k + 1 < logV; k++) {
      for (int v = 0; v < V; v++) {
        if (parent[k][v] < 0) parent[k+1][v] = -1;
        else parent[k+1][v] = parent[k][parent[k][v]];
      }
    }
  }

  int query(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int k = 0; k < logV; k++) {
      if ((depth[v] - depth[u]) >> k & 1) v = parent[k][v];
    }
    if (u == v) return u;

    for (int k = logV-1; k >= 0; k--) {
      if (parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }

  int getDistance(int u, int v) {
    int z = query(u, v);
    return dist[u] + dist[v] - 2 * dist[z];
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N; cin >> N;
  rep(i,0,N-1) {
    int a, b; cin >> a >> b; a--; b--;
    G[a].pb(make_pair(b,1));
    G[b].pb(make_pair(a,1));
  }

  LCA lca(N);
  lca.init(0, -1, 0, 0);
  lca.build();

  int Q; cin >> Q;
  rep(i,0,Q) {
    int a, b; cin >> a >> b; a--; b--;
    cout << lca.getDistance(a, b)+1 << endl;
  }


  return 0;
};
