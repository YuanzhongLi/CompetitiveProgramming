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
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << "\n";
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define endl "\n"
// gcj print用
#define Case(x) printf("Case #%d: ", x);

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
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
};

ll POWLL(ll x, int n) {
  ll ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
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

const int MAX_V = 50;
const int MAX_S = MAX_V * MAX_V + 5;
const ll INF = 1e18;

struct Edge {
  int to, a, b;
  Edge(int to, int a, int b): to(to), a(a), b(b) {}
};

struct Data {
  int v, s;
  ll x;
  Data(int v, int s, ll x): v(v), s(s), x(x) {}
  bool operator < (const Data &a) const {
    return x > a.x;
  }
};

vector<Edge> g[MAX_V];
ll dp[MAX_V][MAX_S+5];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, s;
  cin >> n >> m >> s;

  rep(i, 0, m) {
    int u, v, a, b;
    cin >> u >> v >> a >> b;
    u--; v--;
    g[u].eb(v, a, b);
    g[v].eb(u, a, b);
  }

  vi c(n), d(n);
  rep(i, 0, n) {
    cin >> c[i] >> d[i];
  }

  rep(i, 0, n) {
    rep(j, 0, MAX_S+5) dp[i][j] = INF;
  }

  s = min(s, MAX_S);

  priority_queue<Data> pq;
  auto push = [&](int v, int s, ll x) {
    if (s < 0) return ;
    if (dp[v][s] <= x) return ;
    dp[v][s] = x;
    pq.emplace(v, s, x);
  };

  push(0, s, 0);
  while (!pq.empty()) {
    Data hoge = pq.top(); pq.pop();
    int v = hoge.v, s = hoge.s;
    ll x = hoge.x;
    if (dp[v][s] != x) continue;
    {
      int ns = min(s+c[v], MAX_S);
      push(v, ns, x+d[v]);
    }
    for (Edge e: g[v]) {
      push(e.to, s-e.a, x+e.b);
    }
  }

  rep(i, 1, n) {
    ll ans = INF;
    rep(j, 0, MAX_S+5) {
      chmin(ans, dp[i][j]);
    }
    cout << ans << endl;
  }


  return 0;
};
