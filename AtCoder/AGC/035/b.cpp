#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define BiSearchRangeNum(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y)

static const int MAX = 100005;
static const int WHITE = 0; // 未到達
static const int GRAY = 1; // 到達
static const int BLACK = 2; // 探索済み

int N, M;

set<int> S;

int color[MAX];
vector<int> adj[MAX];

vector<pair<int, int>> ans;

int solve() {
  int ret = 0;
  for (int i = 0; i < MAX; i++) {
    color[i] = WHITE;
  }

  while (!S.empty()) {
    int u = *(S.begin());
    S.erase(u);
    int adjNum = 0;
    for (int j = 0; j < adj[u].size(); j++) {
      int v = adj[u][j];
      if (color[v] == WHITE) adjNum++;
    }
    int base;
    if (adjNum % 2 == 0) {
      base = adjNum;
      color[u] = BLACK;
    } else base = adjNum - 1;
    for (int j = 0; j < adj[u].size(); j++) {
      int v = adj[u][j];
      if (color[v] == BLACK) continue;
      if (base > 0) {
        ans.pb(make_pair(u, v));
        base--;
        ret++;
      }
    }
  }
  return ret;
};

int main() {
  cin >> N >> M;
  int A, B;
  int s;
  rep(i, 0, M) {
    cin >> A >> B;
    adj[A].pb(B);
    adj[B].pb(A);
    S.insert(A);
    S.insert(B);
  }
  int tmp = solve();

  if (M % 2 != 0) {
    cout << -1 << endl;
    return 0;
  }

  if (tmp != M) {
    cout << -1 << endl;
  } else {
    rep(i, 0, ans.size()) {
      cout << ans[i].first << " " << ans[i].second << endl;
    }
  }
};
