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

static const int MAX = 200005;
static const ll INFTY = (1ll << 60);
static const int WHITE = 0; // 未到達
static const int GRAY = 1; // 到達
static const int BLACK = 2; // 探索済み

// <node, cost>
vector<pair<int, ll>> adj[MAX]; // 重み付き有向グラフの隣接リスト表現
int color[MAX];
ll d[MAX];
int p[MAX];

void dijkstra(int s, int V) {
  // <cost, node>
  priority_queue<pair<ll, int>> PQ;
  for (int i = 0; i <= V; i++) {
    d[i] = INFTY;
    color[i] = 0;
  }

  d[s] = 0;
  PQ.push(make_pair(0, s));
  color[s] = GRAY;

  while (!PQ.empty()) {
    pair<int, int> f = PQ.top();
    PQ.pop();
    int u = f.second;
    color[u] = BLACK;

    for (int j = 0; j < adj[u].size(); j++) {
      int v = adj[u][j].first;
      if (color[v] == BLACK) continue;
      if (d[v] > d[u] + adj[u][j].second) {
        d[v] = d[u] + adj[u][j].second;
        p[v] = u; // 経路を求めるために親ノードを更新
        // priority_queueはデフォルトで大きい値を優先するため-1をかける
        PQ.push(make_pair(d[v] * (-1), v));
        color[v] = GRAY;
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T; cin >> T;
  while (T--) {
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    a--; b--; c--;
    int u, v;
    vl P(m);
    rep(i, 0, m) {
      cin >> P[i];
    }
    rep(i, 0, m) {
      ll p = P[i];
      cin >> u >> v;
      u--; v--;
      adj[u].pb(make_pair(v, 1));
      adj[v].pb(make_pair(u, 1));
    }
    sort(All(P));
    ll ans = 0;
    dijkstra(a, n);
    ans += d[b];
    dijkstra(b, n);
    ans += d[c];
    cout << ans << endl;
  }

  return 0;
};
