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
const int INF = 1e9+7;
int dp[1001][200005];

void init() {
  rep(i, 0, 1001) {
    rep(j, 0, 200005) {
      if (j) dp[i][j] = INF;
      else dp[i][j] = 0;
    }
  }

};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int D;  cin >> D;
  int G; cin >> G; G /= 100;
  vi P(D), C(D);
  rep(i, 0, D) {
    cin >> P[i] >> C[i];
    C[i] /= 100;
  }

  init();

  int cnt = 0;
  rep(d, 1, D+1) {
    int n = P[d-1]; // 問題数
    int c = C[d-1];

    int tmp = cnt;
    // debug(tmp);
    rep(i, 0, n) {
      cnt++;
      rep(j, 0, 200005) {
        if (i == n-1) {
          // ボーナス
          if (j - (d*n+c) >= 0) {
            dp[cnt][j] = min({dp[tmp][j-(d*n+c)] + n, dp[cnt-1][j], dp[cnt-1][j-d]+1});
          } else if (j-d >= 0) {
            dp[cnt][j] = min({dp[cnt-1][j], dp[cnt-1][j-d]+1, n});
          } else {
            dp[cnt][j] = min({dp[cnt-1][j], 1, n});
          }
        } else {
          if (j-d < 0) {
            dp[cnt][j] = min(dp[cnt-1][j], 1);
          } else {
            dp[cnt][j] = min(dp[cnt-1][j], dp[cnt-1][j-d]+1);
          }
        }
      }
    }
  }

  cout << dp[cnt][G] << endl;

  // rep(i, 0, cnt+1) {
  //   rep(j, 0, G+1) {
  //     cout << i << " " << j << " " << dp[i][j] << endl;
  //   }
  // }


  return 0;
};
