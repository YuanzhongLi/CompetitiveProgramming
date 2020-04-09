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
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;
#define debug(x) cerr << #x << ": " << (x) << "\n";

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

const ll INF = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  vl X(N), C(N), V(N);
  rep(i, 0, N) {
    cin >> X[i];
  }

  rep(i, 0, N) {
    cin >> C[i];
  }

  rep(i, 0, N) {
    cin >> V[i];
  }

  ll sum[N+1];
  sum[0] = 0;
  rep(i, 1, N+1) sum[i] = sum[i-1] + X[i-1]; // 売却によって得られる金額の累積和

  // dp1[S] := 販売停止中の商品集合がSであるときの両者が最善を尽くしたときの得点
  // dp2[S][k]:= Sが販売停止中であるときにk個財産を売ったときに得られる所持金(sum[k])での得点の最大値

  ll dp1[1 << N], dp2[1 << N][N+1];
  fill(dp2[0], dp2[1 << N], 0);
  for (int S = (1 << N)-1; S >= 0; S--) {
    // 販売中の商品の値段,価値の総和
    ll cos = 0, val = 0;
    rep(i, 0, N) {
      if (!(S & (1 << i))) {
        cos += C[i];
        val += V[i];
      }
    }
    rep(k, 0, N) {
      // 全部買える時
      if (sum[k] >= cos) dp2[S][k] = val;
      else {
        // 一つは買えないものがあるので全部試す
        rep(j, 0, N) {
          if (S & (1 << j)) continue;
          dp2[S][k] = max(dp2[S][k], dp2[S | (1 << j)][k]);
        }
      }
    }
  }

  rep(S, 0, (1 << N)) dp1[S] = dp2[S][__builtin_popcount(S)];
  for (int S = (1 << N)-1; S >= 0; S--) {
    ll tmp = INF;
    rep(i, 0, N) {
      if (S & (1 << i)) continue;
      tmp = min(tmp, dp1[S | (1 << i)]);
    }
    if (tmp != INF) dp1[S] = max(dp1[S], tmp);
  }

  cout << dp1[0] << endl;

  return 0;
};
