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

class Road {
  public:
  int d, c;
  int from, to;
  Road(int d, int c, int from, int to): d(d), c(c), from(from), to(to) {}
  bool operator < (const Road &r) const {
    if (d == r.d) {
      return c < r.c;
    } else {
      return d < r.d;
    }
  }
};

static const int INF = 1e9+7;

int main() {
  int N, M;
  while(cin >> N >> M, N+M) {
    vector<vector<Road>> graph(N);
    vector<int> dist(N, INF);
    dist[0] = 0;
    vector<int> cost(N, INF); // 親ノードとの間のコスト
    cost[0] = 0;
    int U, V, D, C;
    rep(i, 0, M) {
      cin >> U >> V >> D >> C;
      U--;
      V--;
      Road r1 = Road(D, C, U, V);
      Road r2 = Road(D, C, V, U);
      graph[U].pb(r1);
      graph[V].pb(r2);
    }

    priority_queue<Road> pq;
    Road s_r = Road(0, 0, 0, 0);
    pq.push(s_r);
    while (!pq.empty()) {
      auto r = pq.top(); pq.pop();
      int u = r.to;

      if (dist[u] < r.d || cost[u] < r.c) continue;

      for (auto ri: graph[u]) {
        int v = ri.to;
        int d = ri.d;
        int c = ri.c;

        if (dist[u] + d < dist[v] || (dist[v] == dist[u] + d && cost[v] > c)) {
          dist[v] = dist[u] + d;
          cost[v] = c;
          pq.push(ri);
        }
      }
    }

    int ans = 0;
    rep(i, 1, N) {
      ans += cost[i];
    }

    cout << ans << endl;
  }

  return 0;
};
