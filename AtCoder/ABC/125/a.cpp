#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, T;
  cin >> A >> B >> T;
  int ans = (int)((T + 0.5) / A) * B;
  cout << ans << endl;
};
