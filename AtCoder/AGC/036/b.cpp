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

int main() {
  ll N, K;
  cin >> N >> K;
  // 数に対応する<登場した時のindex, 次に登場する時のindex>
  map<int, vector<pair<int, int>>> M;
  // <ある数, その数のindex>, つぎへ移る時のindex
  map<pair<int, int>, int> next;
  vector<int> A(N);
  int a;
  rep(i, 0, N) {
    cin >> a;
    A[i] = a;
    M[a].pb(make_pair(i, -1));
  }
  rep(i, 0, N) {
    int ai = A[i];
    rep(j, 0, M[ai].size()) {
      if (j == M[ai].size() - 1) {
        M[ai][j].second = M[ai][0].first;
        if (M[ai][j].second == N - 1) {
          auto tmp = make_pair(ai, M[ai][j].first);
          next[tmp] = 0;
        } else {
          auto tmp = make_pair(ai, M[ai][j].first);
          next[tmp] = M[ai][j].second + 1;
        }
      } else {
        M[ai][j].second = M[ai][j + 1].first;
        if (M[ai][j].second == N - 1) {
          auto tmp = make_pair(ai, M[ai][j].first);
          next[tmp] = 0;
        } else {
          auto tmp = make_pair(ai, M[ai][j].first);
          next[tmp] = M[ai][j].second + 1;
        }
      }
    }
  }

  vector<int> mark(N, 0);
  mark[0] = 1;
  bool flag = true;
  int loop = 0;
  int curA = A[0];
  int curidx = 0;
  auto curp = make_pair(curA, curidx);
  while (flag) {
    int curA = next[curp];
    if
  }
};
