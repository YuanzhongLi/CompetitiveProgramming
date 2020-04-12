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

const int mod = 1e9+7;

int const MAX_N = 100;
int const MAX_K = 100005;
int dp[MAX_N][MAX_K];
int sum[MAX_N][MAX_K];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, K;
  cin >> N >> K;
  vi A(N);
  rep(i, 0, N) {
    cin >> A[i];
  }

  rep(i, 0, K+1) {
    if (A[0] >= i) {
      dp[0][i] = 1;
    } else {
      dp[0][i] = 0;
    }
  }
  sum[0][0] = dp[0][0];
  rep(i, 1, K+1) {
    sum[0][i] = sum[0][i-1] + dp[0][i];
    sum[0][i] %= mod;
  }

  rep(i, 1, N) {
    rep(j, 0, K+1) {
      int ma = max(0, j - A[i]);
      if (ma == 0) {
        dp[i][j] += sum[i-1][j];
        dp[i][j] %= mod;
      } else {
        dp[i][j] += ((sum[i-1][j] + mod - sum[i-1][j - A[i] - 1]) % mod);
        dp[i][j] %= mod;
      }
    }
    sum[i][0] = dp[i][0];
    rep(j, 1, K+1) {
      sum[i][j] = sum[i][j-1] + dp[i][j];
      sum[i][j] %= mod;
    }

  }

  cout << dp[N-1][K] << endl;

  return 0;
};
