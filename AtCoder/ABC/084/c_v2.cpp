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

static const int INF = 1e9+7;
static const int MAXN = 510;
static const int MAXS = 150005;

vector<vector<int>> dp(MAXN, vector<int> (MAXS, INF));

int main() {
  int N;
  cin >> N;
  vector<vector<int>> csf(N+1, vector<int> (3));
  rep(i, 1, N) {
    rep(j, 0, 3) {
      cin >> csf[i][j];
    }
  }

  rep(i, 0, MAXS) {
    dp[N][i] = i;
  }

  for (int i = N - 1; i > 0; i--) {
    int c = csf[i][0];
    int s = csf[i][1];
    int f = csf[i][2];

    rep(j, 0, MAXS) {
      if (j <= s) {
        int time = s + c;
        dp[i][j] = dp[i+1][time];
      } else {
        int time = ((j + f - 1) / f) * f + c;
        if (time >= MAXS) continue;
        dp[i][j] = dp[i+1][time];
      }
    }
  }

  rep(i, 1, N+1) {
    cout << dp[i][0] << endl;
  }

  return 0;
};
