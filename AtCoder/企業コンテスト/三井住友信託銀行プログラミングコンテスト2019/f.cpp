#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define BiSearchRangeNum(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y)turn idx;
#define deg_to_rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad_to_deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)

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
  ll t1, t2;
  cin >> t1 >> t2;
  ll a1, a2, b1, b2;
  cin >> a1 >> a2 >> b1 >> b2;
  if ((t1 * a1 + t2 * a2) == (b1 * t1 + b2 * t2)) {
    cout << "infinity" << endl;
    return 0;
  }

  // 高橋くんがt1, t2で進む距離
  ll dis_t1 = a1 * t1;
  ll dis_t2 = a2 * t2;
  // 青木くんがt1, t2で進む距離
  ll dis_a1 = b1 * t1;
  ll dis_a2 = b2 * t2;

  if (dis_t1 > dis_a1) {
    if (dis_t1 + dis_t2 > dis_a1 + dis_a2) {
      cout << 0 << endl;
      return 0;
    }

    // t1区間での差
    ll dif1 = dis_t1 - dis_a1;

    // t1, t2合計での差
    ll dif_all = (dis_a1 + dis_a2) - (dis_t1 + dis_t2);

    // あまり
    ll re = dif1 % dif_all;

    ll ans;

    if (re == (ll)0) {
      ans = dif1 / dif_all * (ll) 2;
    } else {
      ans = dif1 / dif_all * (ll) 2 + (ll) 1;
    }

    cout << ans << endl;
  }

  if (dis_a1 > dis_t1) {
    if (dis_a1 + dis_a2 > dis_t1 + dis_t2) {
      cout << 0 << endl;
      return 0;
    }

    // t1区間での差
    ll dif1 = dis_a1 - dis_t1;

    // t1, t2合計での差
    ll dif_all = (dis_t1 + dis_t2) - (dis_a1 + dis_a2);

    // あまり
    ll re = dif1 % dif_all;

    ll ans;

    if (re == (ll)0) {
      ans = dif1 / dif_all * (ll) 2;
    } else {
      ans = dif1 / dif_all * (ll) 2 + (ll) 1;
    }

    cout << ans << endl;
  }

};
