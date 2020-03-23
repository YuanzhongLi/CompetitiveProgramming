#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back

int N, M;
int s, t;

const int MAX = 100005;

vector<int> adj[MAX];

ll solve() {
  vector<vector<ll>> dist(N, vector<ll>(3, -1));
  dist[s][0] = 0;
  queue<pair<int, int>> que;
  que.push({s, 0});
  while (!que.empty()) {
    // 長さが全て同じの有向グラフなのでpriority_queueを使う必要がない
    pair<int, int> cur = que.front();
    que.pop();
    int u = cur.first;
    int up = cur.second;
    rep(i, 0, adj[u].size()) {
      int v = adj[u][i];
      // 隣接するノード（つまり次の行き先候補）のparityは現在のに+1して3で割ったもの
      int vp = (up + 1) % 3;
      if (dist[v][vp] == -1) {
        dist[v][vp] = dist[u][up] + 1;
        que.push({v, vp});
      }
    }
  }

  if (dist[t][0] == -1) return -1;
  else return dist[t][0] / 3;
};


int main() {
  cin >> N >> M;
  int u, v;
  rep(i, 0, M) {
    cin >> u >> v;
    u--; v--;
    adj[u].pb(v);
  }
  cin >> s >> t;
  s--; t--;
  ll ans = solve();
  cout << ans << endl;
};
