#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> A(100001, 0);
  int N;
  cin >> N;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (A[a] == 0) {
      A[a]++;
      continue;
    } else {
      ans++;
    }
  }

  cout << ans << endl;
};
