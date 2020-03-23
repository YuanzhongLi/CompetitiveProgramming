#include <bits/stdc++.h>
using namespace std;

int main() {
  long long W, H, x, y;
  cin >> W >> H >> x >> y;
  double ans = double(W) * double(H) / 2;
  int ans2;

  if (x * 2 == W && y * 2 == H) {
    ans2 = 1;
  } else {
    ans2 = 0;
  }
  cout << ans << " " << ans2 << endl;
};
