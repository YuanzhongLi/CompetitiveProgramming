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

ll dx[9] = {0ll, -1ll, -2ll, 0ll, -1ll, -2ll, 0ll, -1ll, -2ll};
ll dy[9] = {0ll, 0ll, 0ll, -1ll, -1ll, -1ll, -2ll, -2ll, -2ll};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll h, w;
  cin >> h >> w;
  int n;
  cin >> n;

  vl X(n), Y(n);
  rep(i, 0, n) {
    cin >> Y[i] >> X[i];
  }

  set<PLL> black;
  rep(i, 0, n) {
    black.insert(make_pair(Y[i], X[i]));
  }

  vl ans(10, 0ll);
  set<PLL> s;
  rep(i, 0, n) {
    ll xi = X[i];
    ll yi = Y[i];
    rep(j, 0, 9) {
      ll ox = xi + dx[j];
      ll oy = yi + dy[j];
      if (1ll <= ox && ox <= w-2ll && 1ll <= oy && oy <= h-2ll) {
        s.insert(make_pair(oy, ox));
      }
    }
  }

  for (PLL pl: s) {
    ll y = pl.first;
    ll x = pl.second;
    int tmp = 0;
    for (ll i = 0ll; i < 9ll; i++) {
      ll r = i / 3ll;
      ll c = i % 3ll;
      if (Find(black, make_pair(y+r, x+c))) tmp++;
    }
    ans[tmp]++;
  };

  ans[0] = (h-2ll) * (w-2ll);
  rep(i, 1, 10) {
    ans[0] -= ans[i];
  }

  rep(i, 0, 10) {
    cout << ans[i] << endl;
  }

  return 0;
};
