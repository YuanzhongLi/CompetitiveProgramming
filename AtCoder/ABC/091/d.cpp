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
  vector<int> B(N);

  rep(i, 0, N) {
    cin >> A[i];
  }
  rep(i, 0, N) {
    cin >> B[i];
  }

  int ans = 0;
  int T = 1;
  rep(k, 0, 30) {
    int mod = 2 * T;
    vector<int> Amod(N);
    vector<int> Bmod(N);
    rep(i, 0, N) {
      Amod[i] = A[i] % mod;
      Bmod[i] = B[i] % mod;
    }
    sort(All(Amod));

    ll counter = 0;
    rep(i, 0, N) {
      int bi = Bmod[i];
      counter += BiSearchRangeNum(Amod, T - bi, 2 * T - bi) + BiSearchRangeNum(Amod, 3 * T - bi, 4 * T - bi);
    }
    if (counter % 2 == 1) ans += T;
    T *= 2;
  }

  cout << ans << endl;
};
