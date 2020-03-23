#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int l = 1;
  int r = N;

  int ans = 1;

  for (int i = 0; i < M; i++) {
    int L, R;
    cin >> L >> R;
    if (L > r || R < l) {
      ans = 0;
      break;
    }
    if (L >= l && R <= r) {
      r = min(R, r);
      l = max(L, l);
    } else if (L <= l && R >= r) {
      r = min(R, r);
      l = max(L, l);
    } else if (L <= r && R >= r) {
      r = min(R, r);
      l = max(L, l);
    } else {
      r = min(r, R);
      l = max(L, l);
    }
  }

  if (ans == 0) {
    cout << ans << endl;
    return 0;
  }

  ans = r - l + 1;
  cout << ans << endl;

};
