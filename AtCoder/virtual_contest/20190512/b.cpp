#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int ans = 0;

  for (int i = 0; i < n; i++) {
    int fnum = a[i];
    if (fnum % 6 == 0) ans += 3;
    if (fnum % 6 == 2) ans++;
    if (fnum % 6 == 4) ans++;
    if (fnum % 6 == 5) ans += 2;
  }

  cout << ans << endl;
};
