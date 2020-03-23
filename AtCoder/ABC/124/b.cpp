#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int H[N];
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }
  int m;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (i == 0) {
      m = H[i];
      ans += 1;
    } else {
      if (H[i] >= m) {
        ans += 1;
      }
      m = max(m, H[i]);
    }
  }
  cout << ans << endl;
};
