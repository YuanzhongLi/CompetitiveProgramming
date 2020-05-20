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

void print() {
  cout << endl;
}

template <class T>
void print(vector<T> &vec) {
  for (auto& a : vec) {
    cout << a;
    if (&a != &vec.back()) cout << " ";
  }
  cout << endl;
}

template <class T>
void print(vector<T> &vec, ll k){
   ll n = vec.size();
   k = min(k, n);
   rep(i, 0, k-1) cout << vec[i] << " ";
   cout << vec[k-1] << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
  for (auto& vec : df) {
    print(vec);
  }
}

template<class T, class U>
void print(pair<T,U> &p){
  cout << p.first << " " << p.second << "\n";
}

const int INF = 1e9+7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N; cin >> N;

  vvi graph(N);
  vvi d(N, vi(N, INF));

  rep(i, 0, N) rep(j, 0, N) {
    char ch;
    cin >> ch;
    if (ch == '1') {
      graph[i].pb(j);
      graph[j].pb(i);
      d[i][j] = 1;
      d[j][i] = 1;
    }
  }

  vector<bool> visited(N, false);
  vi dist(N, 0);
  queue<int> q; q.push(0);

  bool ok = true;
  while (!q.empty()) {
    int u = q.front(); q.pop();

    if (visited[u]) continue;
    visited[u] = true;

    for (int v: graph[u]) {
      if (visited[v]) continue;

      if (dist[v]) {
        if (dist[v] != dist[u]+1) {
          ok = false;
          break;
        }
      } else {
        dist[v] = dist[u]+1;
        q.push(v);
      }
    }

    if (!ok) break;
  }

  if (!ok) {
    cout << -1 << endl;
    return 0;
  }

  rep(i, 0, N) d[i][i] = 0;

  rep(k, 0, N) {
    rep(i, 0, N) {
      rep(j, 0, N) {
        chmin(d[i][j], d[i][k]+d[k][j]);
      }
    }
  }

  int ans = 0;
  rep(i, 0, N) rep(j, 0, N) {
    if (d[i][j] == INF) continue;
    chmax(ans, d[i][j]);
  }

  cout << ans+1 << endl;

  return 0;
};
