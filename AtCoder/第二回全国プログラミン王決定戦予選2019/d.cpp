#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define BiSearchRangeNum(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y)turn idx;
#define deg_to_rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad_to_deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)

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

static const int MAX = 200001;
static const ll INFTY = 1e15;
static const int WHITE = 0; // 未到達
static const int GRAY = 1; // 到達
static const int BLACK = 2; // 探索済み

// <node, cost>
vector<pair<int, ll>> adj[MAX]; // 重み付き有向グラフの隣接リスト表現
int color[MAX];
ll d[MAX];
int p[MAX];

void dijkstra(int s) {
  // <cost, node>
  priority_queue<pair<ll, int>> PQ;
  for (int i = 0; i < MAX; i++) {
    d[i] = INFTY;
    color[i] = WHITE;
  }

  d[s] = 0;
  PQ.push(make_pair(0, s));
  color[s] = GRAY;

  while (!PQ.empty()) {
    pair<ll, int> f = PQ.top();
    PQ.pop();
		// node
    int u = f.second;
    color[u] = BLACK;

    for (int j = 0; j < adj[u].size(); j++) {
			// node
      int v = adj[u][j].first;
      if (color[v] == BLACK) continue;
      if (d[v] > d[u] + adj[u][j].second) {
        d[v] = d[u] + adj[u][j].second;
        p[v] = u;
        // priority_queueはデフォルトで大きい値を優先するため-1をかける
        PQ.push(make_pair(d[v] * (-1), v));
        color[v] = GRAY;
      }
    }
  }
};

int main() {
	int N, M;
	cin >> N >> M;
	int L, R, C;
	rep(i, 0, N) {
		int idx = N - i;
		adj[idx].pb({ idx - 1, (ll) 0 });
	}
	rep(i, 0, M) {
		cin >> L >> R >> C;
		adj[L].pb({ R, (ll) C });
	}
	dijkstra(1);

	if (d[N] == INFTY) {
		cout << -1 << endl;
	} else {
		cout << d[N] << endl;
	}
};
