#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, C;
  cin >> N >> M >> C;

  vector<int> B(M);
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }

  int ans = 0;

  for (int i = 0; i < N; i++) {
    int total = C;
    for (int j = 0; j < M; j++) {
      int Aij;
      cin >> Aij;
      total += (Aij * B[j]);
    }
    if (total > 0) {
      ans += 1;
    }
  }

  cout << ans << endl;
}