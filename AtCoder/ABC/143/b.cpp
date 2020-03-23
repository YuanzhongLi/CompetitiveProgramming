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
  int N;
  cin >> N;
  vector<int> d(N, 0);
  rep(i, 0, N) {
    cin >> d[i];
  }

  ll ans = 0;
  rep(i, 0, N) {
    int first = d[i];
    rep(j, i + 1, N) {
      int second = d[j];
      ans += (first * second);
    }
  }

  cout << ans << endl;
};
