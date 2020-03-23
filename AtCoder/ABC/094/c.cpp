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
  int N;
  cin >> N;
  vector<int> X(N);
  rep(i, 0, N) {
    cin >> X[i];
  }

  vector<int> ord(N);
  iota(All(ord), 0);

  sort(ord.begin(), ord.end(),  [&](int a, int b) {
    if (X[a] == X[b]) return X[a] > X[b];
    return X[a] < X[b];
  });

  sort(All(X));

  vector<int> ans(N);

  rep(i, 0, N) {
    if (i <= N / 2 - 1) {
      ans[ord[i]] = X[N/2];
    } else {
      ans[ord[i]] = X[N/2 - 1];
    }
  }

  rep(i, 0, N) {
    cout << ans[i] << endl;
  }

  return 0;
};
