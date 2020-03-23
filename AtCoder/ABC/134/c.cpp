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
  vector<int> A(N);
  vector<int> ord(N);
  rep(i, 0, N) {
    cin >> A[i];
    ord[i] = i;
  }
  sort(All(ord), [&] (int a, int b) {
    return A[a] > A[b];
  });
  sort(All(A));
  reverse(All(A));
  vector<int> ans(N);
  rep(i, 0, N) {
    int Ai = A[i];
    int idx = ord[i];
    if (i == 0) {
      ans[idx] = A[1];
    } else {
      ans[idx] = A[0];
    }
  }
  rep(i, 0, N) {
    cout << ans[i] << endl;
  }
};
