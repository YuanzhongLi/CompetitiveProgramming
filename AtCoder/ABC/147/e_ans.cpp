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

const int D = 80*160 + 10;
const int D2 = D*2;
typedef bitset<D2> bs;

int a[100][100];
bs dp[90][90];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  rep(i, 0, h) {
    rep(j, 0, w) {
      int x;
      cin >> x;
      a[i][j] = x;
    }
  }
  rep(i, 0, h) {
    rep(j, 0, w) {
      int y;
      cin >> y;
      a[i][j] = abs(a[i][j] - y);
    }
  }

  dp[0][0][D-a[0][0]] = 1;
  dp[0][0][D+a[0][0]] = 1;
  rep(i, 0, h) {
    rep(j, 0, w) {
      if (i) {
        dp[i][j] |= dp[i-1][j] << a[i][j];
        dp[i][j] |= dp[i-1][j] >> a[i][j];
      }
      if (j) {
        dp[i][j] |= dp[i][j-1] << a[i][j];
        dp[i][j] |= dp[i][j-1] >> a[i][j];
      }
    }
  }

  int ans = D2;
  rep(i, 0, D2) {
    if (dp[h-1][w-1][i]) {
      ans = min(ans, abs(i - D));
    }
  }

  cout << ans << endl;

  return 0;
};
