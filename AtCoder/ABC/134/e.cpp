#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define BiSearchRangeNum(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y)turn idx;
static const int INF = 1e9+7;

// 対象のvectorの [s, e)の範囲でのLIS
int solve(vector<int> &x, int s, int e) {
  int INFTY = 1e9+7;
  vector<int> ret(e - s, INFTY);
  ret[0] = -x[s];
  int size = 1;
  for (int i = s + 1; i < e; i++) {
    int tmp = -x[i];
    if (ret[size - 1] <= tmp) {
      ret[size++] = tmp;
    } else {
      *upper_bound(ret.begin(), ret.end(), tmp) = tmp;
    }
  }
  return size;
};

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, 0, N) {
    cin >> A[i];
  }

  int ans = solve(A, 0, A.size());
  cout << ans << endl;
};
