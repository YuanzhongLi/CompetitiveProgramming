#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j

static const int MAX = 1000007;
static const int WHITE = 0;
static const int BLACK = 1;

vector<int> adj[MAX];
int color[MAX];

int H, W;

queue<int> que;
queue<int> que2;

int solve() {
  int ans = -1;

  while(!que.empty() || !que2.empty()) {
    ans++;
    if (que2.empty()) {
      while(!que.empty()) {
        int u = que.front();
        que.pop();
        rep(i, 0, adj[u].size()) {
          int v = adj[u][i];
          if (color[v] == BLACK) continue;
          color[v] = BLACK;
          que2.push(v);
        }
      }
    } else {
      while(!que2.empty()) {
        int u = que2.front();
        que2.pop();
        rep(i, 0, adj[u].size()) {
          int v = adj[u][i];
          if (color[v] == BLACK) continue;
          color[v] = BLACK;
          que.push(v);
        }
      }
    }
  }
  return ans;
};

int main() {
  cin >> H >> W;
  char A;
  rep(i, 0, H) {
    rep(j, 0, W) {
      cin >> A;
      int nodeNum = i * W + j;
      if ((nodeNum + 1) % W != 0) adj[nodeNum].pb(nodeNum + 1);
      if (nodeNum % W != 0) adj[nodeNum].pb(nodeNum - 1);
      if (nodeNum >= W) adj[nodeNum].pb(nodeNum - W);
      if (nodeNum < (H - 1) * W) adj[nodeNum].pb(nodeNum + W);

      if (A == '.') {
        color[nodeNum] = WHITE;
      }
      if (A == '#') {
        color[nodeNum] = BLACK;
        que.push(nodeNum);
      }
    }
  }
  int ans = solve();
  cout << ans << endl;
};
