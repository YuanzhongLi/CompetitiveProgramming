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

static const int MAX = 400;
static const ll INFTY = 1e15;

// N: node数, M: edge数
ll N, M;
ll dist[MAX][MAX];

// nodeAと nodeBの 距離(Cost) C
ll A[100000], B[100000], C[100000];

void input() {
  cin >> N >> M;
  for (int i = 1; i <= M; i++) cin >> A[i] >> B[i] >> C[i];
};

void floyd() {
  input();
  // 初期化
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      dist[i][j] = INFTY;
    }
    dist[i][i] = 0;
  }

  // 初期node間距離代入
  for (int i = 1; i <= M; i++) {
    chmin(dist[A[i]][B[i]], C[i]);
    chmin(dist[B[i]][A[i]], C[i]);
  }

  // フロイド法によって全点間の最短距離を算出
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      for (int k = 1; k <= N; k++) {
        chmin(dist[j][k], dist[j][i] + dist[i][k]);
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll ans = 1e18;

  floyd();

  rep(i, 1, N+1) {
    ll tmp = 0;
    rep(j, 1, N+1) {
      chmax(tmp, dist[i][j]);
    }
    chmin(ans, tmp);
  }

  cout << ans << endl;


  return 0;
};
