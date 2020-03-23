#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, 0, N) {
    cin >> A[i];
  }

  int ans = A[0];
  rep(i, 0, N) {
    ans = __gcd(ans, A[i]);
  }
  cout << ans << endl;
};
