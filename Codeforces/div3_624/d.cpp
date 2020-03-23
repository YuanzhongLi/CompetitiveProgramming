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
  int t;
  cin >> t;

  int a, b, c;
  rep(i, 0, t) {
    cin >> a >> b >> c;
    int ans = 1e9;
    int A = -1;
    int B = -1;
    int C = -1;
    for (int cA = 1; cA <= 2 * b; cA++) {
      for (int cB = cA; cB <= 2 * b; cB += cA) {
        for (int i = 0; i < 2; ++i) {
          int cC = cB * (c / cB) + i * cB;
          int res = abs(cA - a) + abs(cB - b) + abs(cC - c);
          if (ans > res) {
            ans = res;
            A = cA;
            B = cB;
            C = cC;
          }
        }
      }
    }

    cout << ans << endl << A << " " << B << " " << C << endl;
  }
  return 0;
};
