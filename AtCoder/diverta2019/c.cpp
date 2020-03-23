#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  ll ans = 0;
  int xa, bx, ba;
  xa = bx = ba = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int size = s.size();
    if (s[0] == 'B' && s[size - 1] == 'A') ba++;
    else if (s[size - 1] == 'A') xa++;
    else if (s[0] == 'B') bx++;
    for (int j = 1; j < size; j++) {
      if (s[j - 1] == 'A' && s[j] == 'B') ans++;
    }
  }

  if (xa == 0 && bx == 0) {
    ans += max(0, ba - 1);
  } else {
    ans += min(xa, bx) + ba;
  }

  cout << ans << endl;
};
