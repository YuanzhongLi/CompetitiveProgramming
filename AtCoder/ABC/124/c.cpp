#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int ans1 = 0;
  int ans0 = 0;
  // 1, 0 ...
  for (int i = 0; i < S.size(); i++) {
    int index = i;
    if (index % 2 == 0 && S[i] != '1') {
      ans1 += 1;
    }
    if (index % 2 == 1 && S[i] != '0') {
      ans1 += 1;
    }
  }
  // 0, 1 ...
  for (int i = 0; i < S.size(); i++) {
    int index = i;
    if (index % 2 == 0 && S[i] != '0') {
      ans0 += 1;
    }
    if (index % 2 == 1 && S[i] != '1') {
      ans0 += 1;
    }
  }

  cout << min(ans1, ans0) << endl;
};
