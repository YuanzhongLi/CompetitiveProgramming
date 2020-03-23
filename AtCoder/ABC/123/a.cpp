#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  vector<int> A(5);
  for (int i = 0; i < 5; i++) {
    cin >> A[i];
  }

  cin >> k;

  bool is = false;
  for (int i = 0; i < 5; i++) {
    for (int j = i; j < 5; j++) {
      int dis = abs(A[i] - A[j]);
      if (dis > k) {
        is = true;
        break;
      }
    }
  }

  if (is) {
    cout << ":(" << endl;
  } else {
    cout << "Yay!" << endl;
  }
};
