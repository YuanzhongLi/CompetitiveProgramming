#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define ld long double
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
#define debug(x) cerr << #x << ": " << (x) << "\n";

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<int>>> vvvl;
typedef vector<PI> vpi;
typedef vector<vector<PI>> vvpi;
typedef vector<vector<vector<PI>>> vvvpi;
typedef vector<PLL> vpl;
typedef vector<vector<PLL>> vvpl;
typedef vector<vector<vector<PLL>>> vvvpl;

int POWINT(int x, int n) {
  int ret = 1;
  rep(i, 0, n) ret *= x;
  return ret;
};

ll POWLL(ll x, int n) {
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

const int MAX = 2005;
const int INFTY = 1e9+7;

vector<int> adj[MAX]; // 重み付き有向グラフの隣接リスト表現
bool visited[MAX];
int d[MAX];

void bfs(int s) {
  queue<int> q;
  for (int i = 0; i < MAX; i++) {
    d[i] = INFTY;
    visited[i] = false;;
  }

  d[s] = 0;
  q.push(s);

  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (visited[u]) continue;
    visited[u] = true;
    for (int v: adj[u]) {
      if (visited[v]) continue;
      if (d[v] > d[u]+1) {
        d[v] = d[u]+1;
        q.push(v);
      }
    }
  }
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
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int x, y;
  cin >> x >> y;
  x--; y--;

  rep(i, 0, n-1) {
    adj[i].pb(i+1);
    adj[i+1].pb(i);
  }

  adj[x].pb(y);
  adj[y].pb(x);

  map<PI, int> mp;

  rep(i, 0, n) {
    bfs(i);
    rep (j, 0, n) {
      if (j == i) continue;
      int a = i;
      int b = j;
      if (a > b) swap(a, b);
      mp[make_pair(a, b)] = d[j];
    }
  }

  vi ans(n, 0);
  for (auto ele: mp) {
    ans[ele.second]++;
  }

  rep(i, 1, n) {
    cout << ans[i] << endl;
  }


  return 0;
};
