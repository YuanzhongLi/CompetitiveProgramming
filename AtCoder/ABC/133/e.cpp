#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j

static const int MAX = 100005;
static const int INFTY = (1<<21);
static const int WHITE = 0; // 未到達
static const int GRAY = 1; // 到達
static const int BLACK = 2; // 探索済み
static const ll mod = 1e9+7;

int color[MAX];
int k[MAX];
int p[MAX];

int N, K;

pair<vector<int>, int> adj[MAX];

void solve() {
  queue<int> que;
  rep(i, 0, MAX) {
    color[i] = 0;
    k[i] = -1;
    p[i] = -1;
  }
  k[0] = K;
  adj[0].second = 0;
  p[1] = 0;
  color[1] = GRAY;

  que.push(1);

  while(!que.empty()) {
    int u = que.front();
    que.pop();
    color[u] = BLACK;

    rep(j, 0, adj[u].first.size()) {
      int v = adj[u].first[j];
      adj[v].second += 1;
    }

    k[u] = K - adj[p[u]].second;

    rep(j, 0, adj[u].first.size()) {
      int v = adj[u].first[j];
      if (color[v] == BLACK) continue;
      p[v] = u;
      que.push(v);
    }
  }
};

int main() {
  cin >> N >> K;
  int a, b;
  rep(i, 1, N) {
    scanf("%d %d", &a, &b);
    adj[a].first.pb(b);
    adj[a].second = 0;
    adj[b].first.pb(a);
    adj[b].second = 0;
  }

  solve();
  ll ans = 1;
  rep(i, 1, N + 1) {
    ans *= k[i];
    ans = ans % mod;
  }
  cout << ans << endl;
};
