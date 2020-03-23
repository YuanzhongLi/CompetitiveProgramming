#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long

static const int MAX = 10000;
static const int INFTY = (1<<21);
static const int WHITE = 0; // 未到達
static const int GRAY = 1; // 到達
static const int BLACK = 2; // 探索済み

vector<pair<int, int>> adj[MAX]; // 重み付き有向グラフの隣接リスト表現
int color[MAX];
int d[MAX];
int p[MAX];

void dijkstra(int s) {
  // <cost, node>
  priority_queue<pair<int, int>> PQ;
  for (int i = 0; i < MAX; i++) {
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
        p[v] = u;
        // priority_queueはデフォルトで大きい値を優先するため-1をかける
        PQ.push(make_pair(d[v] * (-1), v));
        color[v] = GRAY;
      }
    }
  }
};

int main() {
  int H, W;
  cin >> H >> W;
  int black = 0;
  char ch;
  rep(i, 1, H * W + 1) {
    cin >> ch;
    if (ch == '.') {
      if ((i % W) != 0) {
        adj[i].push_back(make_pair(i + 1, 1));
      }
      if ((i % W) != 1) {
        adj[i].push_back(make_pair(i - 1, 1));
      }
      if (i > W) {
        adj[i].push_back(make_pair(i - W, 1));
      }
      if (i < (H - 1) * W + 1) {
        adj[i].push_back(make_pair(i + W, 1));
      }
    } else black++;
  }
  dijkstra(1);

  if (color[H * W] != BLACK) {
    cout << -1 << endl;
  } else {
    cout << H * W - black - (d[H * W] + 1) << endl;
  }
};
