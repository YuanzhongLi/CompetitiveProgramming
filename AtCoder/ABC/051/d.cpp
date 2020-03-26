#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
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
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;

int POWINT(int x, int n) {
  int ret = 1;
  rep(i, 0, n) ret *= x;
  return ret;
};

ll POWLL(int x, int n) {
  ll ret = 1;
  rep(i, 0, n) ret *= x;
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

const int INF = 1e9+7;
const int MAX = 101;
static const int WHITE = 0; // 未到達
static const int GRAY = 1; // 到達
static const int BLACK = 2; // 探索済み

// <node, cost>
vector<pair<int, int>> adj[MAX]; // 重み付き有向グラフの隣接リスト表現
int color[MAX];
int d[MAX];

void dijkstra(int s, int e) {
  // <cost, node>
  priority_queue<pair<int, int>> PQ;
  for (int i = 0; i < MAX; i++) {
    d[i] = INF;
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
      if (((u == s) && (v == e)) || ((u == e) && (v == s))) continue;
      if (d[v] > d[u] + adj[u][j].second) {
        d[v] = d[u] + adj[u][j].second;
        // priority_queueはデフォルトで大きい値を優先するため-1をかける
        PQ.push(make_pair(d[v] * (-1), v));
        color[v] = GRAY;
      }
    }
  }
};

struct Edge {
  int from, to, cost;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  int a, b, c;
  vector<Edge> edges(m);
  rep(i, 0, m) {
    cin >> a >> b >> c;
    a--; b--;
    if (a > b) {
      swap(a, b);
    }
    adj[a].pb(make_pair(b, c));
    adj[b].pb(make_pair(a, c));
    edges[i] = Edge{a, b, c};
  }

  int ans = 0;
  for (auto e: edges) {
    int from = e.from;
    int to = e.to;
    int c = e.cost;
    dijkstra(from, to);
    int dis = d[to];
    if (dis < c) ans++;
  }

  cout << ans << endl;

  return 0;
};
