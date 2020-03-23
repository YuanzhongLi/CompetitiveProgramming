#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> c(N);
  for (int i = 0; i < N; i++) {
    cin >> c[i];
  }

  vector<pair<int, int>> bcPair(M);

  for (int i = 0; i < M; i++) {
    cin >> bcPair[i].second >> bcPair[i].first;
  }

  sort(c.begin(), c.end());

  sort(bcPair.begin(), bcPair.end());
  reverse(bcPair.begin(), bcPair.end());

  vector<int> BC(N, 0);
  int count = 0;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < bcPair[i].second; j++) {
      BC[count] = (bcPair[i].first);
      count++;
      if (count == N) break;
    }
    if (count == N) break;
  }

  long long ans = 0;

  for (int i = 0; i < N; i++) {
    ans += max(c[i], BC[i]);
  }

  cout << ans << endl;
};
