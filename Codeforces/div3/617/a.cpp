#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define eb emplace_back
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
  int t;
  cin >> t;

  int n;
  vector<bool> ans(n, false);

  rep(i, 0, t) {
    cin >> n;
    vector<int> A(n);
    rep(j, 0, n) {
      cin >> A[j];
    }

    int total = 0;
    bool hasEven = false;
    bool hasOdd = false;
    rep(j, 0, n) {
      int a = A[j];
      total += a;
      if (a % 2 == 0) {
        hasEven = true;
      } else {
        hasOdd = true;
      }
    }

    if (n == 1) {
      if (A[0] % 2 == 0) {
        ans[i] = false;
      } else {
        ans[i] = true;
      }
    } else {
      if (total % 2 == 1 || (hasEven && hasOdd)) {
        ans[i] = true;
      }
    }
  }

  rep(i, 0, t) {
    if (ans[i]) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }

  return 0;
};
