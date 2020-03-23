#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  char s[N];
  int r = 0, b = 0;
  for (int i = 0; i < N; i++) {
    cin >> s[i];
    if (s[i] == 'R') {
      r += 1;
    } else {
      b += 1;
    }
  }
  if (r > b) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
};
