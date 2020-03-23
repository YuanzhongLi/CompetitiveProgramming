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

// 対象のvectorの [s, e)の範囲でのLIS
vector<int> LIS(vector<int> &x, int s, int e) {
  int INFTY = 1e9+7;
  vector<int> ret(e - s, INFTY);
  ret[0] = x[s];
  int size = 1;
  for (int i = s + 1; i < e; i++) {
    int tmp = x[i];
    if (ret[size - 1] < tmp) {
      ret[size++] = tmp;
    } else {
      *lower_bound(ret.begin(), ret.end(), tmp) = tmp;
    }
  }
  return vector<int> (ret.begin(), ret.begin() + size);
};

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n) {
    cin >> a[i];
  }

  vector<int> ans = LIS(a, 0, a.size());

  cout << ans.size() << endl;
};
