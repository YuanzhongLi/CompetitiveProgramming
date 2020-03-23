#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define BiSearchRangeNum(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y)

int main() {
  ll S;
  cin >> S;
  ll MAX = 1e9;
  ll rem = S % MAX;
  ll quo = S / MAX;
  ll x1, y1, x2, y2, x3, y3;
  x1 = y1 = 0ll;
  x2 = 1ll;
  y2 = 1e9;
  if (rem == 0) {
    x3 = quo;
    y3 = 0;
  } else {
    x3 = quo + 1;
    y3 = (ll)1e9 - rem;
  }
  cout << x1 << " " << y1 << " " << x2 << " "  << y2 << " " << x3 << " " << y3 << endl;
};
