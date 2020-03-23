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
  int R, C, K, N, r, c;
  cin >> R >> C >> K >> N;
  set<pair<int, int>> S;
  vector<int> row(R, 0);
  vector<int> col(C, 0);
  vector<int> ordc(R);
  iota(ordc.begin(), ordc.end(), 0);
  rep(i, 0, N) {
    cin >> r >> c;
    row[r]++;
    col[c]++;
    S.insert(make_pair(r, c));
  }

  sort(ordc.begin(), ordc.end(), [&](int a, int b) {
    return col[a], col[b];
  });

  sort(All(col));

  int ans = 0;

  rep(i, 0, row.size()) {
    int num0 = row[i];
    int idx0 = lbidx(col, K - num0);
    while () {
      
    }
    int num1 = num0 - 1;
    int idx1 = lbidx(col, K - num1);
  }

};
