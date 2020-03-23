#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j

const int mod = 2019;

int main() {
  ll L, R;
  cin >> L >> R;
  if (R - L >=2018) {
    cout << 0 << endl;
    return 0;
  }
  vector<int> modnums(R - L + 1);
  rep(i, 0, R - L + 1) {
    int num = (L + i) % mod;
    modnums[i] = num;
  }
  vector<int> ans;
  rep(i, 0, modnums.size() - 1) {
    rep(j, i+1,  modnums.size()) {
      int num = (modnums[i] * modnums[j]) % mod;
      ans.pb(num);
    }
  }
  sort(All(ans));
  cout << ans[0] << endl;
};
