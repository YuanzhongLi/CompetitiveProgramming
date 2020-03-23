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

static const int MAXV = 100005;
vector<int> to[MAXV];

vector<bool> visited(MAXV, false);
vector<bool> calculated(MAXV, false);
int dp[MAXV];
int dfs(int v) {
  if (visited[v]) {
    if (!calculated[v]) return -1; // 閉路検出
    return dp[v];
  }

  visited[v] = true;
  dp[v] = 0;
  for (int u: to[v]) {
    int res = dfs(u);
    if (res == -1) return -1; // 閉路検出
    dp[v] = max(dp[v], res+1);
  }
  calculated[v] = true;
  return dp[v];
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
  int N, M;
  cin >> N >> M;
  int x, y;
  rep(i, 0, M) {
    cin >> x >> y;
    x--; y--;
    to[x].pb(y);
  }

  int ans = 0;

  rep(v, 0, N) {
    ans = max(ans, dfs(v));
  }

  cout << ans << endl;
};
