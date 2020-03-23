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

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  cout << (x * y) / 2 << endl;
};
