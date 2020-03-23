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

int digit (ll n) {
  int ret = 0;
  while (n != 0) {
    n /= (ll)10;
    ret += 1;
  }

  // cout << ret << endl;
  return ret;
};

bool solve(ll mid, ll A, ll B, ll X) {
  // cout << "solve: " << A * mid + B * digit(mid) << endl;
  return (A * mid + B * digit(mid)) <= X;
};

ll BF(ll A, ll B, ll X) {
    ll ng = min((ll)1e9, X) + 1;
    ll ok = 0; // 解が存在しない

    while (abs(ng - ok) > 1) {
        ll mid = (ng + ok) / 2;
        if (solve(mid, A, B, X)) {
            ok = mid;
        } else {
            ng = mid;
        }
        // cout << mid << endl;
    }
    return ok;
    // ok が最終的に到達する値になる
};

int main() {
  ll A, B, X;
  cin >> A >> B >> X;
  int N = 1e9;
  if (BF(A, B, X) >= N) {
    cout << N << endl;
  } else {
    cout << BF(A, B, X) << endl;
  }
};
