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
  vector<int> A(N+1);
  vector<int> B(N);
  rep(i, 0, N+1) {
    cin >> A[i];
  }
  rep(i, 0, N) {
    cin >> B[i];
  }
  ll ans = 0;
  rep(i, 0, N) {
    int bi = B[i];
    int ai = A[i];
    if (bi >= ai) {
      ans += ai;
      if (bi - ai >= A[i + 1]) {
        ans += A[i + 1];
        A[i + 1] = 0;
      } else {
        A[i + 1] -= bi - ai;
        ans += bi - ai;
      }
    } else {
      ans += bi;
    }
  }

  cout << ans << endl;
};
