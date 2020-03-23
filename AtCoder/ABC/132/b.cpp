#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, 0, n) {
    cin >> p[i];
  }

  int ans = 0;

  rep(i, 1, n -1) {
    int MAX, MIN;
    MAX = max(p[i - 1], p[i + 1]);
    MIN = min(p[i - 1], p[i + 1]);
    if (MIN <= p[i] && p[i] <= MAX) {
      ans+=1;
    }
  }
  cout << ans << endl;
};
