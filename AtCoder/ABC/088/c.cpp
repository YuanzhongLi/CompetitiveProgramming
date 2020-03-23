#include <bits/stdc++.h>
using namespace std;

int main() {
  int c1, c2, c3, c4, c5, c6, c7, c8, c9;
  cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6 >> c7 >> c8 >> c9;
  int total = (c1 + c5 + c9);
  if ( total == (c4 + c8 + c3) && total == (c7 + c2 + c6) && total == (c3 + c5 + c7) && total == (c6 + c8 + c1) && total == (c9 + c2 + c4)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
};
