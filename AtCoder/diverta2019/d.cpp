#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll N;
  cin >> N;
  ll ans = 0;
  if (N == 1 || N == 2) {
    cout << ans << endl;
    return 0;
  }
  ll sqrt_n = sqrt(N);
  for (int i = 1; i <= sqrt_n; i++) {
    if (N % i == 0) {
      ll small_divisor = i;
      ll big_divisor = (ll)(N / i);
      // cout << "i : " << i << ", s : " << small_divisor << ", b : " << big_divisor << endl;
      if (big_divisor - small_divisor > 1) ans += (big_divisor - 1);
    }
  }

  cout << ans << endl;
};
