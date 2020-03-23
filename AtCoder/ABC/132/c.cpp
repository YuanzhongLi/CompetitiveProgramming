#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long

int main() {
  int N;
  cin >> N;
  vector<int> d(N);
  rep(i, 0, N) cin >> d[i];
  sort(d.begin(), d.end());
  int half = N / 2;
  int r = d[half];
  int l = d[half - 1];
  if (r > l) {
    cout << r - l << endl;
  } else cout << 0 << endl;
};
