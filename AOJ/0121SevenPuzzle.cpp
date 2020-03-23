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

// x^n
int POW(int x, int n) {
  int ret = 1;
  rep(i, 0, n) {
    ret *= x;
  }
  return ret;
};

struct Puzzle {
  int panel[8];
  int x, y; // 0のx, y
};

int calc_state(Puzzle p) {
  int ret = 0;
  rep(i, 0, 8) {
    ret += p.panel[i] * POW(8, i);
  }
  return ret;
};



// state, distance
map<int, int> T;
map<int, bool> visited;

int dx[4] = { 0, 0, 1, -1 }; // u, d, r, l
int dy[4] = { -1, 1, 0, 0 }; // u, d, r, l

void bfs() {
  Puzzle init_p = { 0, 1, 2, 3, 4, 5, 6, 7, 0, 0 };
  queue<Puzzle> q;
  q.push(init_p);
  T[calc_state(init_p)] = 0;
  Puzzle p;
  int x, y;
  int x2, y2;
  while(!q.empty()) {
    p = q.front(); q.pop();
    int p_state = calc_state(p);
    if (Find(visited, p_state)) continue;
    visited.emplace(p_state, true);
    x = p.x;
    y = p.y;
    // 0の動かし先
    rep(i, 0, 4) {
      x2 = x + dx[i];
      y2 = y + dy[i];
      if (0 <= x2 && x2 < 4 && 0 <= y2 && y2 < 2) {
        Puzzle tmp = p;
        swap(tmp.panel[y * 4 + x], tmp.panel[y2 * 4 + x2]); // 交換
        // 0の位置を更新
        tmp.x = x2;
        tmp.y = y2;
        int tmp_state = calc_state(tmp);
        if (!(Find(visited, tmp_state))) { // 探索済み出ない
          if (Find(T, tmp_state)) {
            T[tmp_state] = min(T[tmp_state], T[p_state] + 1);
          } else {
            T[tmp_state] = T[p_state] + 1;
          }
          q.emplace(tmp);
        }
      }
    }
  }
};

int main() {
  bfs();

  int n;
  Puzzle p;
  while (true) {
    rep(i, 0, 8) {
      if (!(cin >> n)) return 0;
      p.panel[i] = n;
      if (n == 0) {
        p.x = i % 4;
        p.y = i / 4;
      }
    }
    int p_state = calc_state(p);
    cout << T[p_state] << endl;
  }
};
