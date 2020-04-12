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
#define Case(x) cout << "Case #" << x << ": ";

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

int pascal[505][505];

void init_pascal() {
  pascal[1][1] = 1;
  rep(r, 2, 30) {
    rep(k, 1, r+1) {
      pascal[r][k] = pascal[r-1][k-1] + pascal[r-1][k];
    }
  }
};

vector<vector<vector<bool>>> visited(505, vector<vector<bool>> (505, vector<bool> (3, false)));

struct Point {
  int r, k, dir;
};

map<int, vpi> mp;
map<Point, int> mp2;
map<Point, Point> par;

int dr[3] = {1, 1, 0}; // d-left, d-right, right
int dk[3] = {0, 1, 1};

vpi bfs() {
  Point s1 = {1, 1, 0};
  Point s2 = {1, 1, 1};
  mp2[s1] = mp2[s2] = 1;
  queue<Point> q;
  q.push(s1); q.push(s2);
  while (!q.empty()) {
    Point u = q.front(); q.pop();
    if (visited[u.r][u.k][u.dir]) continue;
    visited[u.r][u.k][u.dir] = true;

    rep(i, 0, 3) {
      int v_r = u.r + dr[i];
      int v_k = u.k + dk[i];
      if (v_k <= v_r) {

      }
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init_pascal();

  int T;
  cin >> T;
  rep(t, 0, T) {
    int N;
    cin >> N;
  }





  return 0;
};
