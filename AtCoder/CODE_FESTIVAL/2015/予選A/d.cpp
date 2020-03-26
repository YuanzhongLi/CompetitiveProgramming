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

bool check(ll mid, vector<ll> &X, ll n) {
  // cout << mid << endl;
  int ret = true;
  ll l = 1ll; // 左からl-1車両目まで点検が終わった
  rep(i, 0, X.size()) {
    ll xi = X[i];
    // cout << "xi : " << xi;

    if (i < X.size() - 1) {
      if (l < xi) {
        if (xi - l > mid) {
          ret = false;
          break;
        } else {
          l = max(l, max(max(xi+1ll, xi+1ll+(mid-(xi-l))/2ll), xi+(mid - (max((xi-l), 0ll)*2ll)+1ll)));
        }
      } else {
        l = max(l, xi+mid+1ll);
      }
      // cout << ", l : " << l << endl;
    } else {
      if (l < xi) {
        if (xi - l > mid) {
          ret = false;
          break;
        } else {
          l = max(l, max(max(xi+1ll, xi+1ll+(mid-(xi-l))/2ll), xi+(mid - (max((xi-l), 0ll)*2ll)+1ll)));
        }
      } else {
        l = max(l, xi+mid+1ll);
      }

      // cout << ", l : " << l << endl;
      if (l < n+1ll) {
        ret = false;
        break;
      }
    }
  }

  return ret;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  int m;
  cin >> n >> m;
  vector<ll> X(m);
  rep(i, 0, m) {
    cin >> X[i];
  }

  ll ok = (1ll << 60), ng = -1ll;

  while (abs(ok - ng) > 1) {
    ll mid = (ng + ok) / 2;
    if (check(mid, X, n)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  // cout << endl;
  cout << ok << endl;

  return 0;
};
