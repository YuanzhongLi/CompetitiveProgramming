#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j

static const int MAX = 100005;
static const int WHITE = 0;
static const int BLACK = 1;
static const int NOT_COLLOR = -1;

vector<pair<int, int>> adj[MAX];
int color[MAX];
int p[MAX];
// 親ノードとの距離
int dist[MAX];

int N;

void solve() {
  rep(i, 0, MAX) {
    color[i] = NOT_COLLOR;
    p[i] = -1;
    dist[i] = -1;
  }
  dist[0] = 0;
  dist[1] = 0;
  color[0] = WHITE;

  queue<int> que;
  que.push(1);

  while(!que.empty()) {
    int u = que.front();
    que.pop();

    if (dist[u] % 2 == 0) {
      color[u] = color[p[u]];
    } else {
      if (color[p[u]] == WHITE) {
        color[u] = BLACK;
      } else {
        color[u] = WHITE;
      }
    }

    rep(i, 0, adj[u].size()) {
      int v = adj[u][i].first;
      if (color[v] != NOT_COLLOR) continue;
      que.push(v);
      p[v] = u;
      dist[v] = adj[u][i].second;
    }
  }

};

int main() {
  cin >> N;
  int u, v, w;
  rep(i, 1, N) {
    scanf("%d %d %d", &u, &v, &w);
    adj[u].pb(make_pair(v, w));
    adj[v].pb(make_pair(u, w));
  }
  adj[0].pb(make_pair(1, 0));

  solve();

  rep(i, 1, N + 1) {
    printf("%d\n", color[i]);
  }
};
