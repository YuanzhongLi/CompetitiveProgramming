#include <bits/stdc++.h>
using namespace std;

int main() {
  int S;
  cin >> S;
  int front = S / 100;
  int back = S % 100;

  string ans;
  if (front > 12 || front == 0) {
    if (back >= 1 && back <= 12) {
      ans = "YYMM";
    } else ans = "NA";
  } else {
    if (back > 12 || back == 0) {
      ans = "MMYY";
    } else ans = "AMBIGUOUS";
  }

  cout << ans << endl;
};
