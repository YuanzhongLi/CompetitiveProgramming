#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  string S;
  cin >> n >> q >> S;
  vector<int> AC(n);
  int cnt = 0;
  AC[0] = 0;
  for (int i = 1; i < n; i++) {
    if (S[i] == 'C' && S[i - 1] == 'A') {
      cnt++;
    }
    AC[i] = cnt;
  }

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    if (l == 1) cout << AC[r - 1] << endl;
    else cout << AC[r - 1] - AC[l - 1] << endl;
  }
};
