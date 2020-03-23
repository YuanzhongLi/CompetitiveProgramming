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

bool upper(vector<int> &x) {
  bool ret = true;
  rep(i, 1, x.size()) {
    if (x[i] < x[i - 1]) {
      ret = false;
      break;
    }
  }
  return ret;
};

int main() {
  int N;
  cin >> N;
  vector<int> p(N);
  rep(i, 0, N) {
    cin >> p[i];
  }
  if (upper(p)) {
    cout << "YES" << endl;
    return 0;
  }

  bool flag = false;
  rep(i, 0, N) {
    rep(j, i + 1, N) {
      vector<int> tmp = p;
      swap(tmp[i], tmp[j]);
      if (upper(tmp)) {
        flag = true;
        break;
      }
    }
    if (flag) {
      break;
    }
  }

  if (flag) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

};
