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
  vector<int> L(N);
  rep(i, 0, N) {
    cin >> L[i];
  }
  sort(L.begin(), L.end());

  int ans = 0;

  rep(i, 0, N) {
    int b = L[i];
    rep(j, i + 1, N) {
      int c = L[j];
      int plus = lower_bound(L.begin() + j + 1, L.end(), b + c) - lower_bound(L.begin() + j + 1, L.end(), abs(b - c));
      ans += plus;
    }
  }

  cout << ans << endl;
};
