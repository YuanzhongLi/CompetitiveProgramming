#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
  int mCount = 0;
  ll ans = 0;
  int n;
  cin >> n;
  vector<int> absVec(n);
  for (int i = 0; i < n; i++) {
    int A;
    cin >> A;
    if (A < 0) mCount++;
    absVec[i] = abs(A);
    ans += absVec[i];
  }

  if (mCount % 2 == 0) cout << ans << endl;
  else {
    sort(absVec.begin(), absVec.end());
    cout << ans - 2 * absVec[0] << endl;
  }
};
