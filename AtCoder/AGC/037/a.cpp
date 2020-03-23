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
  string S;
  cin >> S;
  if (S.size() == 1) {
    cout << 1 << endl;
    return 0;
  }

  int ans = 0;
  char curChar = 'A';
  int num = 1;

  int idx = 0;

  while (idx < S.size()) {
    char c = S[idx];
    if (curChar != c) {
      ans++;
      curChar = c;
      idx++;
    } else {
      if (idx == S.size() - 1) {
        break;
      }
      ans++;
      idx += 2;
      curChar = 'A';
    }
  }

  cout << ans << endl;
};
