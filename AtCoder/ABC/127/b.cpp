#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, D, x;
  cin >> r >> D >> x;
  int ans[11];
  ans[0] = x;
  for (int i = 1; i < 11; i++) {
    ans[i] = r * ans[i - 1] - D;
    cout << ans[i] << endl;
  }
};
