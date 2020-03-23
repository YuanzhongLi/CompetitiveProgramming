#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int y, a, h, o;
  y = a = h = o = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'y') y++;
    if (s[i] == 'a') a++;
    if (s[i] == 'h') h++;
    if (s[i] == 'o') o++;
  }

  if (y == 1 && a == 1 && h == 1 && o == 2) cout << "YES" << endl;
  else cout << "NO" << endl;
};
