#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define llbidx(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y) // 二要素間の距離
#define deg2rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad2deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)
#define Find(set, element) set.find(element) != set.end()
#define Decimal(x) printf("%.10f\n", x) // 小数点を10桁まで表示
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

const ll LINF = 1e18;

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

  int n, m;
  cin >> n >> m;
  vvl g(n, vl(n, LINF));
  rep(i, 0, n) g[i][i] = 0;
  rep(i, 0, m) {
    int v, u;
    ll w;
    cin >> v >> u >> w;
    v--; u--;
    g[u][v] = w;
    g[v][u] = w;
  }

  // floyd
  rep(l, 0, n) {
    rep(i, 0, n) {
      rep(j, 0, n) {
        chmin(g[i][j], g[i][l]+g[l][j]);
      }
    }
  }

  int k;
  cin >> k;
  vi A(k);
  rep(i, 0, k) {
    cin >> A[i]; A[i]--;
  }

  int Q; cin >> Q;
  vi b(Q);
  rep(i, 0, Q) {
    cin >> b[i]; b[i]--;
  }

  ll t = 0;
  vl S(k-1);
  rep(i, 0, k-1) {
    S[i] = g[A[i]][A[i+1]];
    chmax(t, g[A[i]][A[i+1]]);
  }

  ll ok = t;
  ll ng = -1;

  bool flag;
  auto check = [&] (ll mid) {
    vi tmp; // i番目からi+1番目で石を使う必要あり
    rep(i, 0, k-1) {
      if (S[i] > mid) {
        tmp.pb(i);
      }
    }
    int K = tmp.size();
    int s = K + Q, t = s + 1;
    Dinic dinic(K + Q + 2);

    rep(i, 0, K) {
      dinic.add_edge(s, i, 1);
    }

    rep(j, 0, Q) {
      dinic.add_edge(K + j, t, 1);
    }

    rep (j, 0, Q) {
      int stone = b[j];
      rep(i, 0, K) {
        int stamp = tmp[i];
        ll dist = g[stone][A[stamp+1]];
        if (dist <= mid) {
          dinic.add_edge(i, K+j, 1);
        }
      }
    }

    int match = dinic.max_flow(s, t);

    if (match >= tmp.size()) {
      flag = true;
    } else {
      flag = false;
    }

    return ;
  };

  while (abs(ok - ng) > 1) {
    ll mid = (ok+ng) / 2;
    check(mid);
    if (flag)  {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  cout << ok << endl;

  return 0;
};
