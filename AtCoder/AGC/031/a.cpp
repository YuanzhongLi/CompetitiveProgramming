#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;

  vector<int> cnt(26, 0);

  for (int i = 0; i < N; i++) {
    int index = S[i] - 'a';
    cnt[index] += 1;
  }

  int mod = 1e9 + 7;
  int ans = 1;
  for (int i = 0; i < 26; i++) {
    ans *= (cnt[i] + 1);
    ans %= mod;
  }

  ans = (ans + mod - 1) % mod;
  cout << ans << endl;
};
