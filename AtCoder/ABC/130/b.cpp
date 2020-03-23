#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> L(N);
  for (int i = 0; i < N; i++) {
    cin >> L[i];
  }

  int D = 0;
  int ans = 1;

  for (int i = 0; i < N; i++) {
    if (D + L[i] <= X) {
      ans += 1;
      D += L[i];
    } else {
      break;
    }
  }

  cout << ans << endl;
};
