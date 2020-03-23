#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define llbidx(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y) // 二要素間の距離
#define deg2rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad2deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)
#define Find(set, element) set.find(element) != set.end()

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;

template<class T>
inline bool chmax(T &a, T b) {
  if(a < b) {
    a = b;
    return true;
  }
  return false;
};

template<class T>
inline bool chmin(T &a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
};

int main() {
  int N, M, X;
  cin >> N >> M >> X;
  vector<int> A(M);
  rep(i, 0, M) {
    cin >> A[i];
  }

  vector<int> MASS(N+1, 0);
  rep(i, 0, M) {
    MASS[A[i]] = 1;
  }

  int l_cost = 0;

  rep(i, 0, X) {
    l_cost += MASS[i];
  }

  int r_cost = 0;
  rep(i, X, N+1) {
    r_cost += MASS[i];
  }

  int ans = min(l_cost, r_cost);

  cout << ans << endl;
};
