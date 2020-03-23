#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int ans;
  int x = A + B;
  int y = 2 * A - 1;
  int z = 2 * B - 1;
  ans = max(x, max(y, z));
  cout << ans << endl;
};
