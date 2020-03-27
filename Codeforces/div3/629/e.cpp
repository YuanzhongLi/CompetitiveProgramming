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

int T;
vi par, dist;
vi tin, tout;
vvi adj;

void dfs(int u, int p = -1, int dep = 0) {
  par[u] = p;
  dist[u] = dep;
  tin[u] = T++;
  for (int v: adj[u]) {
    if (v == p) continue;
    dfs(v, u, dep+1);
  }
  tout[u] = T++;
};

// uがvの先祖かどうか
bool isAnc(int u, int v) {
  return tin[u] <= tin[v] && tout[v] <= tout[u];
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  T = 0;
  par = dist = vi(n);
  tin = tout = vi(n);
  adj = vvi(n);
  rep(i, 0, n-1) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  dfs(0);

  rep(i, 0, m) {
    int k;
    cin >> k;
    vi A(k);
    rep(j, 0, k) {
      cin >> A[j];
      A[j]--;
    }

    int max_depth = -1;
    int max_depth_v;
    rep(j, 0, k) {
      int a = A[j];
      if (dist[a] > max_depth) {
        max_depth = dist[a];
        max_depth_v = a;
      }
    }

    rep(j, 0, k) {
      if (A[j] == 0) continue;
      A[j] = par[A[j]];
    }

    bool flag = true;
    for (int v: A) {
      if (isAnc(v, max_depth_v)) continue;
      flag = false;
      break;
    }

    if (flag) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }


  return 0;
};
