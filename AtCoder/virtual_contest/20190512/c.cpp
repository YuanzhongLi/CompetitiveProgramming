#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, H, A, B, C, D, E;
ll AD;
ll BC;

vector<int> dp(N + 2);

ll ans = 0;

// i日目、k残り日数
void choice(int i, ll BC, ll AD) {
  int k = N - i;
  if (dp[i] > E) {
    dp[i + 1] = dp[i] - E;
  }
  else if (BC <= AD) {
    ans += C;
    dp[i + 1] = dp[i] + D;
  } else {
    if (A > k * C) {
      ans += C;
      dp[i + 1] = dp[i] + D;
    } else {
      ans += A;
      dp[i + 1] = dp[i] + B;
    }
  }
};


int main() {
  cin >> N >> H >> A >> B >> C >> D >> E;
  dp[1] = H;

  AD = A * D;
  BC = B * C;

  for (int i = 1; i < N + 1; i++) {
    choice(i, BC, AD);
  }

  cout << ans << endl;

};
