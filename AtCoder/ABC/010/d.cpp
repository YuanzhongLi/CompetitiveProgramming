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

static const int INF = (1<<30);

struct Dinic {
  // icapは元々の容量でcapと比較することでmatchingがどれかわかる
  struct Edge {
    int to, cap, icap, rev;
  };

  int V;
  vector<vector<Edge>> G;
  vector<int> level;
  vector<bool> used;

  Dinic(int V): V(V), G(V) {}

  void add_edge(int from, int to, int cap) {
    G[from].pb((Edge){ to, cap, cap, (int) G[to].size() });
    G[to].pb((Edge) { from, 0, 0, (int) G[from].size()-1 });
  }
  // sからの到達するのにかかる最短のステップ数を調べるbfsで調べる
  void bfs(int s) {
    level.assign(V, -1);
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (auto &e: G[v]) {
        // level[e.to] == -1つまり未"発見"
        if (e.cap > 0 && level[e.to] < 0) {
          level[e.to] = level[v] + 1;
          q.push(e.to);
        }
      }
    }
  }

  int dfs(int v, int t, int f) {
    if (v == t) return f;

    used[v] = true;
    rep (i, 0, G[v].size()) {
      Edge &e = G[v][i];
      // 容量ありでかつ辺の先はより遠い
      if (e.cap > 0 && level[v] < level[e.to] && !used[e.to]) {
        int d = dfs(e.to, t, min(f, e.cap));
        if (d > 0) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }

    return 0;
  }

  int max_flow(int s, int t) {
    int ret = 0, f;
    while (bfs(s), level[t] >= 0)  {
      used.assign(V, false);
      while ((f = dfs(s, t, INF)) > 0) {
        ret += f;
      }
    }
    return ret;
  }

  // xは片方のnodeの数
  vector<pair<int, int>> matching_pair(int s, int t, int x) {
    vector<pair<int, int>> ret;
    int match = max_flow(s, t);
    rep(i, 0, x) {
      for (auto e: G[i]) {
        if (e.cap == 0 && e.icap == 1) {
          ret.pb(make_pair(i, e.to));
        }
      }
    }
    return ret;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, G, E; cin >> N >> G >> E;
  Dinic dinic(N+1);
  int t = N;
  int s = 0;
  rep(i, 0, G) {
    int p; cin >> p;
    dinic.add_edge(p, t, 1);
  }

  rep(i, 0, E) {
    int a, b; cin >> a >> b;
    dinic.add_edge(a, b, 1);
    dinic.add_edge(b, a, 1);
  }

  int ans = dinic.max_flow(s, t);

  cout << ans << endl;

  return 0;
};
