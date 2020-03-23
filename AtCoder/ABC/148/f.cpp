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

vector<int> bfs(int s, vector<vector<int>> &graph) {
  vector<bool> visited((int)graph.size(), false);
  vector<int> dist((int)graph.size(), INF);
  dist[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (visited[u]) continue;
    visited[u] = true;
    for (int v: graph[u]) {
      if (visited[v]) continue;
      if (dist[v] > dist[u] + 1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }

  return dist;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, u, v;
  cin >> N >> u >> v;
  u--; v--;
  vector<vector<int>> graph(N);
  int a, b;
  rep(i, 0, N-1) {
    cin >> a >> b;
    a--; b--;
    graph[a].pb(b);
    graph[b].pb(a);
  }

  vector<int> dist_from_init_A = bfs(v, graph);
  vector<int> dist_from_init_T = bfs(u, graph);

  int ans = 0;
  rep(i, 0, N) {
    int d_from_t = dist_from_init_T[i];
    int d_from_a = dist_from_init_A[i];
    if (d_from_t <= d_from_a) {
      ans = max(ans, d_from_a - 1);
    }
  }

  cout << ans << endl;

  return 0;
};
