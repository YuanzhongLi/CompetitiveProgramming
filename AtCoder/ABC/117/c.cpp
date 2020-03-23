#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j

const int INF = 1e9+7;

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> X(M);
  rep(i, 0, M) {
    cin >> X[i];
  }

  if (N >= M) {
    cout << 0 << endl;
    return 0;
  }

  sort(All(X));

  // 間隔
  vector<int> dist(M - 1);
  rep(i, 0, M - 1) {
    dist[i] = X[i + 1] - X[i];
  }
  sort(All(dist));
  int ans = 0;
  rep(i, 0, dist.size() - (N - 1)) {
    ans += dist[i];
  }
  cout << ans << endl;
};
