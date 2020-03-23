#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j

int lbidx(vector<int> x, int y) {
  auto itr = lower_bound(x.begin(), x.end(), y);
  int idx = itr - x.begin();
  return idx;
};

int upidx(vector<int> x, int y) {
  auto itr = upper_bound(x.begin(), x.end(), y);
  int idx = itr - x.begin();
  return idx;
}

int func(int x) {
  if (x % 2 == 0) {
    return x / 2;
  }
  return 3 * x + 1;
};

int main() {
  int s;
  cin >> s;
  set<int> S;
  S.insert(s);
  int counter = 1;
  int ans;
  while (1) {
    counter++;
    s = func(s);
    if (S.find(s) != S.end()) {
      ans = counter;
      break;
    }
    S.insert(s);
  }

  cout << ans << endl;
};
