#include <bits/stdc++.h>
using namespace std;

long long lcm (long long a, long long b) {
  return (a / __gcd(a, b)) * b;
}

int main () {
  int N;
  cin >> N;
  vector<long long> T(N);
  for (int i = 0; i < N; i++) {
    cin >> T[i];
  }

  long long ans = 1;
  for (int i = 0; i < N; i++) {
    ans = lcm(ans, T[i]);
  }
  cout << ans << endl;
};
