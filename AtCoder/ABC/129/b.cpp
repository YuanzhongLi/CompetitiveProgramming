#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }

  vector<int> s(n - 1);
  for (int i = 0; i < n - 1; i++) {
    int s1, s2;
    s1 = s2 = 0;
    for (int j = 0; j <= i; j++) {
      s1 += w[j];
    }
    for (int l = i + 1; l < n; l++) {
      s2 += w[l];
    }
    s[i] = abs(s1 - s2);
  }

  sort(s.begin(), s.end());

  cout << s[0] << endl;
};
