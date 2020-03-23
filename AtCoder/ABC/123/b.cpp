#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v(5);
  vector<int> remainder;
  for (int i = 0; i < 5; i++) {
    int value;
    cin >> value;
    int r = value % 10;
    int s = value / 10;
    if (r == 0) {
      v[i] = s * 10;
    } else {
      remainder.push_back(r);
      v[i] = (s + 1) * 10;
    }
  }
  int ans = 0;
  if (remainder.empty()) {
    for (int i = 0; i < 5; i++) {
      ans += v[i];
    }

    cout << ans << endl;
  } else {
    sort(remainder.begin(), remainder.end());
    for (int i = 0; i < 5; i++) {
      ans += v[i];
    }
    ans -= 10;
    ans += remainder[0];
    cout << ans << endl;
  }
};
