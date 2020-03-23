#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;
  vector<long long> v(5);
  for (int i = 0; i < 5; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());
  long long ans = 0;
  long long r = n % v[0];
  long long s;
  if (r == 0) {
    s = n / v[0];
  } else {
    s = (n / v[0]) + 1;
  }
  ans += (s + 4);
  cout << ans << endl;
};
