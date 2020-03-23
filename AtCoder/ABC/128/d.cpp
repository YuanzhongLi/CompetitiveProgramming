#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> V(N);
  rep(i, 0, N) {
    cin >> V[i];
  }

  vector<int> ans;

  // l左からとる個数, r右からとる個数
  rep(l, 0, N + 1) {
    rep(r, 0, N - l + 1) {
      if (l + r > K) continue;
      // 残った使える操作の回数
      int remK = K - l - r;
      // 取り出した数
      vector<int> pick;
      rep(i, 0, l) {
        pick.pb(V[i]);
      }
      rep(i, 0, r) {
        pick.pb(V[N - 1 - i]);
      }
      sort(All(pick));
      int tmp = 0;
      rep(i, 0, pick.size()) {
        if (pick[i] < 0 && remK > 0) {
          remK--;
        } else {
          tmp += pick[i];
        }
      }
      ans.pb(tmp);
    }
  }
  sort(All(ans));
  reverse(All(ans));
  cout << ans[0] << endl;
};
