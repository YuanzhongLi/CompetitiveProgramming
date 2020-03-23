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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  deque<ll> dq(n);
  rep(i, 0, n) {
    cin >> dq[i];
  }

  vector<vector<vector<ll>>> dp(2, vector<vector<ll>> (3005, vector<ll> (3005, 0ll)));
  rep(i, 0, n) {
    dp[0][i][i+1] = dq[i];
    dp[1][i][i+1] = -dq[i];
  }

  rep(diff, 2, n+1) {
    rep(l, 0, n+1-diff) {
      int r = l + diff;

      rep(p, 0, 2) {
        int op;
        if (p == 0) {
          op = 1;
        } else {
          op = 0;
        }

        if (p == 0) {
          dp[p][l][r] = max(dq[l] + dp[op][l+1][r], dq[r-1] + dp[op][l][r-1]);
        } else {
          dp[p][l][r] = min(-dq[l] + dp[op][l+1][r], -dq[r-1] + dp[op][l][r-1]);
        }
      }
    }
  }

  cout << dp[0][0][n] << endl;

  return 0;
};
