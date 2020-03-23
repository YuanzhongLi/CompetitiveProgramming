#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, S, T;
  cin >> N >> S >> T;
  vector<int> w(N, 0);
  int ans = 0;
  cin >> w[0];
  for (int i = 1; i < N; i++) {
    int W;
    cin >> W;
    w[i] = w[i - 1] + W;
  }
  for (int i = 0; i < N; i++) {
    if (w[i] >= S && w[i] <= T) ans++;
  }

  cout << ans << endl;
};
