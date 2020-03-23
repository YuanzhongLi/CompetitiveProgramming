#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j

int main() {
  int N;
  cin >> N;
  vector<int> b(N);
  // 1のindexのところ
  vector<int> num1idx;
  rep(i, 0, N) {
    cin >> b[i];
  }

  vector<int> ans;

  rep(i, 0, N) {
    for (int j = b.size() - 1; j >= 0; j--) {
      if (b[j] == j + 1) {
        ans.pb(b[j]);
        b.erase(b.begin() + j);
        break;
      }
    }
  }

  if (ans.size() != N) {
    cout << -1 << endl;
    return 0;
  }
  reverse(All(ans));
  rep(i, 0, N) {
    cout << ans[i] << endl;
  }
};
