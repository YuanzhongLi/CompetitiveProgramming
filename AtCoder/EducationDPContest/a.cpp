#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define BiSearchRangeNum(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y)

#define inf 1e9;

int main() {
  int N;
  cin >> N;
  vector<int> cost(N+1, 0);
  vector<int> heights(N+1, 0);
  cost[0] = inf;
  rep(i, 0, N) {
    cin >> heights[i+1];
  }

  rep(i, 2, N+1) {
    cost[i] = min(abs(heights[i] - heights[i - 2]) + cost[i - 2], abs(heights[i] - heights[i - 1]) + cost[i - 1]);
  }

  cout << cost[N] << endl;

  return 0;
};
