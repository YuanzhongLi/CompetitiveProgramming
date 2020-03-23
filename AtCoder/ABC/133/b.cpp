#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j

int main() {
  int N, D;
  cin >> N >> D;
  vector<int> cor[N];
  int X;
  rep(i, 0, N) {
    rep(j, 0, D) {
      cin >> X;
      cor[i].pb(X);
    }
  }
  int ans = 0;
  rep(i, 0, N - 1) {
    vector<int> p1 = cor[i];
    rep(j, i+1, N) {
      int sqdis = 0;
      vector<int> p2 = cor[j];
      rep(k, 0, D) {
        sqdis += (p1[k] - p2[k]) * (p1[k] - p2[k]);
      }
      int dis = sqrt(sqdis);
      if (dis * dis == sqdis) {
        ans++;
      }
    }
  }

  cout << ans << endl;
};
