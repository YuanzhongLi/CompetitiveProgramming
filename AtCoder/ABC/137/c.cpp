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
  unordered_map<string, ll> m;
  string s;
  rep(i, 0, N) {
    cin >> s;
    sort(All(s));
    if (m.count(s) > 0) {
      m[s] += 1;
    } else {
      m[s] = 1;
    }
  }

  ll ans = 0;
  for (auto it = m.begin(); it != m.end(); it++) {
    if (it->second == 1) continue;
    ll tmp = it->second;
    ans += tmp * (tmp - 1) / ((ll) 2);
  }
  cout << ans << endl;
};
