#include <bits/stdc++.h>
using namespace std;

int main() {
  int K;
  vector<int> n(3);
  for(int i = 0; i < 3; i++) {
    cin >> n[i];
  }
  cin >> K;
  for (int i = 0; i < K; i++) {
    sort(n.begin(), n.end());
    reverse(n.begin(), n.end());
    n[0] *= 2;
  }
  int ans = 0;
  for (int i = 0; i < 3; i++) {
    ans += n[i];
  }
  cout << ans << endl;
};
