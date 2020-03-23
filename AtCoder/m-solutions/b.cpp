#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int lose = 0;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == 'x') lose++;
  }
  if (lose >= 7) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
};
