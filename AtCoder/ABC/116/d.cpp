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
  int N, K;
  cin >> N >> K;
  priority_queue<pair<ll, int>> menu; // <美味しさ, 種類>
  vector<pair<ll, int>> order;
  map<int, int> used;
  ll ans = 0;
  rep(i, 0, N) {
    int tmpt;
    ll tmpd;
    cin >> tmpt >> tmpd;
    menu.push(make_pair(tmpd, tmpt));
  }
  rep(i, 0, K) {
    auto tmp = menu.top();
    menu.pop();
    order.push_back(tmp);
    ans += tmp.first;
    used[tmp.second]++;
  }
  ll sz = (ll)used.size();
  ans += sz * sz;

  ll tmpAns = ans;
  for (int i = K - 1; i >=0; i--) {
    if (used[order[i].second] == 1) continue;
    while(menu.size() > 0) {
      // 交換する候補
      auto tmp = menu.top();
      menu.pop();
      // 交換する候補の種類が今までのorderにあるかいなか
      if (used[tmp.second] == 0) {
        // orderの中で二品以上のものとなっている
        auto tmpOut = order[i];
        used[tmpOut.second]--;
        used[tmp.second]++;
        tmpAns = tmpAns - tmpOut.first + tmp.first + 2 * sz + 1;
        sz++;
        ans = max(ans, tmpAns);
        order[i] = tmp;
        break;
      }
    }
  }

  cout << ans << endl;
};
