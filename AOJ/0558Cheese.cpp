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

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;

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

static const int INF = 1e9+7;

int grid[1005][1005];
vector<vector<bool>> visited(1005, vector<bool> (1005, false));
vector<int> dis(1005 * 1005, INF);
int H, W, N;
int dx[4] = { 0, 1, 0, -1 }; // N, E, S, W
int dy[4] = { -1, 0, 1, 0 }; // N, E, S, W

int bfs(int s, int e) {
  // visited, dis 初期化
  rep(i, 0, H) {
    rep(j, 0, W) {
      visited[i][j] = false;
      dis[i * W + j] = INF;
    }
  }

  queue<int> q;
  q.push(s);
  dis[s] = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    int uy = u / W;
    int ux = u % W;
    if (visited[uy][ux]) continue;
    if (u == e) {
      break;
    }
    visited[uy][ux] = true;
    rep(i, 0, 4) {
      int vy = u / W + dy[i];
      int vx = u % W + dx[i];
      int v = vy * W + vx;
      if (0 <= vx && vx < W && 0 <= vy && vy < H) {
        if (grid[vy][vx] != -1 && !visited[vy][vx]) {
          q.push(v);
          dis[v] = min(dis[v], dis[u] + 1);
        }
      }
    }
  }

  return dis[e];
};

int main() {
  cin >> H >> W >> N;
  vector<int> points(N+1, 0);

  char ch;
  int s;
  rep(i, 0, H) {
    rep(j, 0, W) {
      cin >> ch;
      if (ch == 'S') {
        s = i * W + j;
        grid[i][j] = 0;
        points[0] = i * W + j;
      } else if (ch == 'X') {
        grid[i][j] = -1;
      } else if (ch == '.') {
        grid[i][j] = 0;
      } else {
        grid[i][j] = (int) ch - 48;
        points[grid[i][j]] = i * W + j;
      }
    }
  }

  int ans = 0;
  rep(i, 0, N) {
    ans += bfs(points[i], points[i+1]);
  }
  cout << ans << endl;
};
