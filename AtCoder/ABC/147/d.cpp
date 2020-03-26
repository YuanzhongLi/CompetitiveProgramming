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
#define Decimal(x) printf("%.10f\n", x) // 小数点を10桁まで表示
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;

int POWINT(int x, int n) {
  int ret = 1;
  rep(i, 0, n) ret *= x;
  return ret;
};

ll POWLL(int x, int n) {
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

const ll mod = 1e9+7;

int dp1[60][300005]; // dp[i][j]: i桁目が1の個数の累積
int dp0[60][300005]; // dp[i][j]: i桁目が0の個数の累積

ll two[61];
void init() {
  two[0] = 1ll;
  rep(i, 1, 61) {
    two[i] = (two[i-1] * 2ll) % mod;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<ll> A(n);
  rep(i, 0, n) {
    cin >> A[i];
  }

  init();

  for (int i = n-1; i >= 0; i--) {
    ll a = A[i];
    rep(j, 0, 60) {
      if ((a >> j) & 1 == 1) {
        dp1[j][i] = dp1[j][i+1]+1;
        dp0[j][i] = dp0[j][i+1];
      } else {
        dp0[j][i] = dp0[j][i+1]+1;
        dp1[j][i] = dp1[j][i+1];
      }
    }
  }

  ll ans = 0ll;

  rep(i, 0, n-1) {
    ll a = A[i];
    rep(j, 0, 60) {
      int one = dp1[j][i+1]; // j桁目が1の個数
      int zero = dp0[j][i+1];
      if ((a >> j) & 1 == 1) {
        ans += ((ll)two[j] * zero);
        ans %= mod;
      } else {
        ans += ((ll)two[j] * one);
        ans %= mod;
      }
    }
  }

  cout << ans << endl;

  return 0;
};
