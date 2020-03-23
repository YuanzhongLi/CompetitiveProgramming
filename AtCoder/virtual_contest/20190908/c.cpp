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
  string s;
  cin >> s;
  vector<int> idxs;
  rep(i, 0, s.size() - 1) {
    if (s[i] == 'W' && s[i + 1] == 'A') {
      idxs.push_back(i + 1);
    }
  }
  // rep(i, 0, idxs.size()) {
  //   cout << idxs[i] << " ";
  // }
  // cout << endl;

  if (idxs.size() == 0) {
    cout << s << endl;
    return 0;
  }

  rep(i, 0, idxs.size()) {
    int idx = idxs[i];
    s[idx] = 'C';
    bool flag = true;
    while(flag) {
      if (idx - 1 == 0) {
        s[idx - 1] = 'A';
        flag = false;
      } else {
        if (s[idx - 2] != 'W') {
          s[idx - 1] = 'A';
          flag = false;
        } else {
          s[idx - 1] = 'C';
          idx--;
        }
      }
    }
  }

  cout << s << endl;

};
