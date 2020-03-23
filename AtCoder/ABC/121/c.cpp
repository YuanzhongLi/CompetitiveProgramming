#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<pair<long long, int>> pairs(N);
  for (int i = 0; i < N; i++) {
    long long A;
    int B;
    cin >> A >> B;
    pairs[i] = make_pair(A, B);
  }

  sort(pairs.begin(), pairs.end());

  int buys = 0;
  int index = 0;
  int overbuys;
  long long ans = 0;

  while (buys < M) {
    buys += pairs[index].second;
    ans += (pairs[index].first * pairs[index].second);
    if (buys >= M) {
      break;
    }
    index += 1;
  }

  ans -= ((buys - M) * pairs[index].first);

  cout << ans << endl;
}