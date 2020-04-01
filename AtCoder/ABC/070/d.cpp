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

template<class T>
inline bool chmin(T &a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
};
const int MAX = 100005;
const ll INF = 1ll << 60;
// cost, node
vector<pair<ll, int>> adj[MAX];
vl dist(MAX, INF);
vector<bool> visited(MAX, false);

void dijkstra(int s) {
  // cost(neg), node
  priority_queue<pair<ll, int>> pq;
  dist[s] = 0ll;
  pq.push(make_pair(0ll, s));
  while (!pq.empty()) {
    auto pu = pq.top(); pq.pop();
    ll cu = -pu.first;
    int u = pu.second;

    if (visited[u]) continue;
    visited[u] = true;

    for (auto pv: adj[u]) {
      ll cv = pv.first;
      int v = pv.second;
      if (visited[v]) continue;
      if (dist[v] > dist[u] + cv) {
        dist[v] = dist[u] + cv;
        pq.push(make_pair(dist[v]*-1ll, v));
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int a, b;
  ll c;
  rep(i, 0, n-1) {
    cin >> a >> b >> c;
    a--; b--;
    adj[a].pb(make_pair(c, b));
    adj[b].pb(make_pair(c, a));
  }

  int q, k;
  cin >> q >> k;
  k--;
  dijkstra(k);

  int x, y;
  rep(i, 0, q) {
    cin >> x >> y;
    x--; y--;
    cout << dist[x] + dist[y] << endl;
  }


  return 0;
};
