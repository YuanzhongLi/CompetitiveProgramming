#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i, 0, N) {
    cin >> A[i];
  }
  vector<ll> ans(N);
  ll allA = 0;
  rep(i, 0, N) {
    allA += A[i];
  }
  ll halfallA = allA / 2ll;

  ll x0 = halfallA;
  for (int i = 1; i < N -1; i+=2) {
    x0 -= A[i];
  }
  ans[0] = x0;
  rep(i, 1, N) {
    ans[i] = A[i - 1] - ans[i - 1];
  }
  rep(i, 0, N) {
    printf("%d\n", ans[i] * 2);
  }

};
