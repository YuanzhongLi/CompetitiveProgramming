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

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;

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

ll solve(ll money) {
  ll cur_m = money;
  ll ret = 0;
  while (1) {
    if (cur_m >= 10ll) {
      ll q = cur_m / 10;
      ll cash_b = q;
      ll rem = cur_m % 10;
      ll spend = q * 10;
      ret += spend;

      cur_m = cash_b + rem;
    } else {
      ret += cur_m;
      break;
    }
  }

  return ret;
};

int main() {
  int t;
  cin >> t;
  vector<ll> ans(t);
  ll x;
  rep(i, 0, t) {
    cin >> x;
    ans[i] = solve(x);
  }

  rep(i, 0, t) {
    cout << ans[i] << endl;
  }
};
