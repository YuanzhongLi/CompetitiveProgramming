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

  sort(ord.begin(), ord.end(),  [&](int a, int b) {
    return A[a] < A[b];
  });

  rep(i, 0, N) {
    if (i == N - 1) {
      cout << ord[i] + 1 << endl;
    } else {
      cout << ord[i] + 1 << " ";
    }
  }
};
