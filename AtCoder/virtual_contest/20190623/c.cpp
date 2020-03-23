#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> R(N);
  for (int i = 0; i < N; i++) {
    cin >> R[i];
  }

  sort(R.begin(), R.end());

  double ans = 0;
  for (int i = 0; i < K; i++) {
    ans = (ans + R[N - K + i]) / 2;
  }

  printf("%lf\n", ans);
};
