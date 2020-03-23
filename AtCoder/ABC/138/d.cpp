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

int main() {
  int N, Q;
  cin >> N >> Q;

  vector<vector<int>> graph (N+1);

  int a, b;
  rep(i, 0, N - 1) {
    cin >> a >> b;
    graph[a].pb(b);
    graph[b].pb(a);
  }

  vector<ll> cnts(N+1, 0ll);

  int p;
  ll x;
  rep(i, 0, Q) {
    cin >> p;
    cin >> x;
    cnts[p] += x;
  }

  int color[N+1];
  rep(i, 0, N) {
    color[i] = 0;
  }

  queue<int> q;
  q.push(1);
  color[1] = 1;

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    color[u] = 2;

    rep(j, 0, graph[u].size()) {
      int v = graph[u][j];
      if (color[v] == 2) continue;
      cnts[v] += cnts[u];
      q.push(v);
      color[v] = 1;
    }
  }

  rep(i, 0, N) {
    int num = i+1;
    cout << cnts[num] << endl;
  }
};
