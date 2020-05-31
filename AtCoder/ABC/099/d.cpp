#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (ll)s; i < (ll)n; i++)
#define rrep(i,n,e) for (int i = (ll)n-1; i >= (ll)e; i--)
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define llbidx(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y) // 二要素間の距離
// #define M_PI 3.14159265358979323846 // CFでは定義しておく必要あり
#define deg2rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad2deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)
#define Find(set, element) set.find(element) != set.end()
#define Decimal(x) cout << fixed << setprecision(10) << x << endl; // 小数点を10桁まで表示
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
};

template <class T>
void print(vector<T> &vec) {
  for (auto& a : vec) {
    cout << a;
    if (&a != &vec.back()) cout << " ";
  }
  cout << endl;
};

template <class T>
void print(vector<T> &vec, ll k){
   ll n = vec.size();
   k = min(k, n);
   rep(i, 0, k-1) cout << vec[i] << " ";
   cout << vec[k-1] << endl;
};

template <class T>
void print(vector<vector<T>> &df) {
  for (auto& vec : df) {
    print(vec);
  }
};

template<class T, class U>
void print(pair<T,U> &p){
  cout << p.first << " " << p.second << "\n";
};

const int INF = 1e9+7;
const int MAX_N = 505;
const int MAX_C = 30;

vvi D(MAX_C, vi(MAX_C));
vvi table(3, vi(MAX_C, 0));
vvi c(MAX_N, vi(MAX_N));

int ans = INF;
int C;
void dfs(set<int> s, int diff) {
  if ((int)s.size() >= 3) {
    chmin(ans, diff);
    return;
  }

  rep(i, 0, C) { // 色iを選ぶ
    if (Find(s, i)) continue;

    int tmp_diff = diff;
    set<int> tmp_s = s;
    tmp_s.insert(i);

    rep(j, 0, C) { // jをiに塗り替える
      tmp_diff += table[s.size()][j] * D[j][i];
    }

    dfs(tmp_s, tmp_diff);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N; cin >> N;
  cin >> C;

  rep(i, 0, C) rep(j, 0, C) cin >> D[i][j];

  rep(i, 0, N) rep(j, 0, N) {
    cin >> c[i][j];
    c[i][j]--;
  }

  rep(i, 0, N*N) {
    int x = i % N;
    int y = i / N;
    int color = c[y][x];
    rep (j, 0, 3) {
      if ((x+y+2) % 3 == j) {
        table[j][color]++;
      }
    }
  }

  set<int> fs;
  dfs(fs, 0);
  cout << ans << endl;

  return 0;
};
