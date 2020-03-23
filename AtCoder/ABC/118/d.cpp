#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long

int MAX = 100001;
int INF = -(1e9+7);

vector<int> p(10);

int main() {
  p[1] = 2;
  p[2] = 5;
  p[3] = 5;
  p[4] = 4;
  p[5] = 5;
  p[6] = 6;
  p[7] = 3;
  p[8] = 7;
  p[9] = 6;

  int N, M;
  cin >> N >> M;
  vector<int> dp(MAX, INF); // i本マッチで作れる桁数
  dp[0] = 0;

  vector<int> A(M);
  rep(i, 0, M) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());

  rep(i, 1, N + 1) {
    rep(j, 0, A.size()) {
      int a = A[j];
      int cost = p[a];
      if (i - cost < 0) continue;
      if (dp[i - cost] != INF) {
        dp[i] = max(dp[i - cost] + 1, dp[i]);
        continue;
      }
    }
  }

  int tmp = N;

  for (int i = dp[N]; i > 0; i--) {
    rep(j, 0, A.size()) {
      int a = A[j];
      int cost = p[a];
      if (tmp - cost < 0) continue;
      if (dp[tmp - cost] == dp[tmp] - 1) {
        cout << a;
        tmp -= cost;
        break;
      }
    }
  }
  cout << endl;

};
