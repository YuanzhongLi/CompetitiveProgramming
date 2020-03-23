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
#define Decimal(x) printf("%.10f\n", x) // 小数点を10桁まで表示
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;

int POWINT(int x, int n) {
  int ret = 1;
  rep(i, 0, n) ret *= x;
  return ret;
};

ll POWLL(int x, int n) {
  ll ret = 1;
  rep(i, 0, n) ret *= x;
  return ret;
};

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

struct state {
  int s, ship;
};

int main() {
  int N, M;
  while (cin >> N >> M, N+M) {
    vector<vector<int>> l_g(N, vector<int> (N, INF));
    vector<vector<int>> s_g(N, vector<int> (N, INF));

    vector<vector<int>> l_dist(N, vector<int> (N, INF));
    vector<vector<int>> s_dist(N, vector<int> (N, INF));
    rep(i, 0, N) {
      l_dist[i][i] = s_dist[i][i] = 0;
    }


    int x, y, t;
    char sl;
    rep(i, 0, M) {
      cin >> x >> y >> t >> sl;
      x--;
      y--;
      if (sl == 'L') {
        l_g[x][y] = min(l_g[x][y], t);
        l_g[y][x] = min(l_g[y][x], t);
        l_dist[x][y] = min(l_dist[x][y], t);
        l_dist[y][x] = min(l_dist[y][x], t);
      } else {
        s_g[x][y] = min(s_g[x][y], t);
        s_g[y][x] = min(s_g[y][x], t);
        s_dist[x][y] = min(s_dist[x][y], t);
        s_dist[y][x] = min(s_dist[y][x], t);
      }
    }

    rep(k, 0, N) {
      rep(i, 0, N) {
        rep(j, 0, N) {
          l_dist[i][j] = min(l_dist[i][j], l_dist[i][k] + l_dist[k][j]);
          s_dist[i][j] = min(s_dist[i][j], s_dist[i][k] + s_dist[k][j]);
        }
      }
    }

    int r;
    cin >> r;
    vector<int> z(r);
    rep(i, 0, r) {
      cin >> z[i];
      z[i]--;
    }

    vector<int> dp(N, INF);
    dp[z[0]] = 0;

    rep(i, 1, r) {
      vector<int> next(N, INF);
      rep (from, 0, N) { // ship from (船がfromにある)
        if (dp[from] == INF) continue;
        next[from] = min(next[from], dp[from] + l_dist[z[i - 1]][z[i]]); // not use ship
        rep (to , 0, N) { // ship to
          next[to] = min(next[to], dp[from] + l_dist[z[i - 1]][from] + s_dist[from][to] + l_dist[to][z[i]]);
        }
      }
      dp = next;
    }

    cout << *min_element(begin(dp), end(dp)) << endl;
  }

  return 0;
};
