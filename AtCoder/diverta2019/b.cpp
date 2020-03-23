#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  int ans = 0;
  for (int i = 0; i <= n / r; i++) {
    if (i * r > n) break;
    for (int j = 0; j <= ((n - i * r) / g); j++) {
      int ij = r * i + g * j;
      if (ij > 3000) break;
      if ((n - ij) % b == 0) ans++;
    }
  }
  cout << ans << endl;
};
