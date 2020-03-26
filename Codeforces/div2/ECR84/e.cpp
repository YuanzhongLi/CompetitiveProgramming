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

const ll mod = 998244353;

ll dp[200005]; // dp[i] = 10^i
void init() {
  dp[0] = 1ll;
  rep(i, 1, 200005) {
    dp[i] = (dp[i-1] * 10LL) % mod;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  init();
  for (int i = 1; i <= n; i++) {
    if (i == n) {
      cout << 10;
      continue;
    }
    ll mid = (ll)max(n - 1 - i, 0);
    ll side = 2ll;

    // middle
    mid *= 810ll;
    mid %= mod;
    int mid_re = max(0, n - i - 2);
    mid *= dp[mid_re];
    mid %= mod;

    // side
    side *= 90ll;
    side %= mod;
    int side_re = max(0, n - i - 1);
    side *= dp[side_re];
    side %= mod;

    ll out = (mid + side);
    out %= mod;
    cout << out;
    if (i < n) cout << " ";
  }

  cout << endl;

  return 0;
};
