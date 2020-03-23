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

const int INF = 1e9+7;

int solve(int p, int q, vector<int> A) {
  // (i, j)を解放するのに必要なコスト
  int dp[q+1][q+2];

  // 初期化
  rep(i, 0, q+1) {
    dp[i][i+1] = 0;
  }

  // 幅が小さい順にdpを埋めていく
  for (int w = 2; w <= q+1; w++) {
    for (int i = 0; i + w <= q+1; i++) {
      // dp[i][j]を計算する
      int j = i + w, t = INT_MAX;

      // 最初に解放する囚人を全て試し、最小コストのものを探す
      for (int k = i + 1; k < j; k++) {
        t = min(t, dp[i][k] + dp[k][j]);
      }

      // 最初の解放では解放する囚人に関わらずA[j]-A[i]-2の金貨が必要
      dp[i][j] = t + A[j] - A[i] - 2;
    }
  }

  return dp[0][q+1];
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  int P, Q;
  rep(t, 0, T) {
    cin >> P >> Q;
    vector<int> A;
    rep(i, 0, Q) {
      int tmp;
      cin >> tmp;
      A.pb(tmp);
    }
    A.pb(0); A.pb(P+1);
    sort(All(A));
    int ans = solve(P, Q, A);
    printf("Case #%d: %d\n", t+1, ans);
  }

  return 0;
};
