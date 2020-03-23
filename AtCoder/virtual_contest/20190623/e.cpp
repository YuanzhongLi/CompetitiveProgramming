#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int l = 0;

  long long ans = 0;

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] > l) {
      cnt++;
    } else {
      cnt = 1;
    }
    ans += cnt;
    l = A[i];
  }
  cout << ans << endl;
};
