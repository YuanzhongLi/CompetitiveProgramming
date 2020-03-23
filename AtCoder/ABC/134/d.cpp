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

vector<int> divisor(int n) {
  vector<int> ret;
  for(int i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  return (ret);
}


int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, 0, N) {
    cin >> A[i];
  }

  vector<int> counter(N + 1, 0);
  int M = 0;
  vector<int> ans;

  bool flag = true;

  for (int i = N; i > 0; i--) {
    int ai = A[i - 1];
    int tmp = counter[i];
    if (ai == 1) {
      if (tmp % 2 == 0) {
        ans.pb(i);
        M++;
        for (int j = 1; j * j <= i; j++) {
          if (i % j == 0) {
            counter[j]++;
            if (j * j != i) counter[i / j]++;
          }
        }
      } else if (tmp % 2 == 1) {
        continue;
      }
    } else if (ai == 0) {
      if (tmp % 2 == 0) {
        continue;
      } else if (tmp % 2 == 1) {
        ans.pb(i);
        M++;
        for (int j = 1; j * j <= i; j++) {
          if (i % j == 0) {
            counter[j]++;
            if (j * j != i) counter[i / j]++;
          }
        }
      }
    }
  }

  cout << M << endl;
  if (M > 0) {
    rep(i, 0, ans.size()) {
      cout << ans[i] << endl;
    }
  }

};
