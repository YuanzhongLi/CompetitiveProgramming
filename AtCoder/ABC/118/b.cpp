#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> food(M, 0);
  int K;
  int A;
  rep(i, 0, N) {
    cin >> K;
    rep(j, 0, K) {
      cin >> A;
      food[A - 1]++;
    }
  }
  int ans = 0;
  rep(i, 0 , M) {
    if (food[i] == N) ans++;
  }
  cout << ans << endl;
};
