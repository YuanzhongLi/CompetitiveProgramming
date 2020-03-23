#include <bits/stdc++.h>
using namespace std;

bool valid(char s) {
  return  (s == 'A' || s == 'C' || s == 'G' || s == 'T');
};

int main() {
  string S;
  cin >> S;
  int n = S.size();
  vector<int> ans(n, 0);

  for (int i = 0; i < n; i++) {
    if (valid(S[i])) {
      for (int j = i; j < n; j++) {
        if (valid(S[j])) ans[i]++;
        else break;
      }
    }
  }

  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  cout << ans[0] << endl;
};
