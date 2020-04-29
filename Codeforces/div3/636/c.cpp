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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T; cin >> T;

  while (T--) {
    int n; cin >> n;
    vl A(n);
    rep(i, 0, n) {
      cin >> A[i];
    }

    vvl pos(n), neg(n);
    int cur_p = 0, cur_n = 0;

    rep(i, 0, n) {
      if (i == 0) {
        if (A[0] > 0) pos[0].pb(A[0]);
        else neg[0].pb(A[0]);
        continue;
      }

      ll cur = A[i];
      ll prev = A[i-1];
      if (cur < 0ll && prev < 0ll) {
        neg[cur_n].pb(cur);
      } else if (cur > 0ll && prev > 0ll) {
        pos[cur_p].pb(cur);
      } else if (cur < 0ll && prev > 0ll) {
        cur_n++;
        neg[cur_n].pb(cur);
      } else if (cur > 0ll && prev < 0ll) {
        cur_p++;
        pos[cur_p].pb(cur);
      }
    }

    ll ans = 0;
    rep(i, 0, n) {
      if (pos[i].empty()) continue;
      sort(All(pos[i]));
      reverse(All(pos[i]));
      ans += pos[i][0];
    }

    rep(i, 0, n) {
      if (neg[i].empty()) continue;
      sort(All(neg[i]));
      reverse(All(neg[i]));
      ans += neg[i][0];
    }
    cout << ans << endl;
  }

  return 0;
};
