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

int H, W;
vector<vector<int>> grid(101, vector<int> (101, 0));
vector<vector<bool>> visited(101, vector<bool> (101, false));

// r, l, u, d
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
  while (cin >> H >> W, H+W) {
    // grid, visited初期化
    char ch;
    rep(i, 0, H) {
      rep(j, 0, W) {
        cin >> ch;
        if (ch == '#') {
          grid[i][j] = 0;
        } else if (ch == '*') {
          grid[i][j] = 1;
        } else {
          grid[i][j] = 2;
        }
        visited[i][j] = false;
      }
    }

    // bfs
    int ans = 0;
    rep(i, 0, H*W) {
      int row = i / W;
      int col = i % W;
      if (visited[row][col]) {
        continue;
      }

      int type = grid[row][col];
      ans += 1;
      queue<int> q;
      q.push(i);
      while (!q.empty()) {
        int v = q.front(); q.pop();
        int y = v / W;
        int x = v % W;
        if (visited[y][x]) continue;
        visited[y][x] = true;


        rep(j, 0, 4) {
          int ny = y+dy[j];
          int nx = x+dx[j];
          if (0 <= nx && nx < W && 0 <= ny && ny < H) {
            if (!visited[ny][nx] && grid[ny][nx] == type) {
              int n = ny * W + nx;
              q.push(n);
            }
          }
        }
      }
    }

    // print ans
    cout << ans << endl;
  }

  return 0;
};
