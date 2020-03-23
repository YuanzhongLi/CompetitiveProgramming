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
#define Decimal(x) printf("%.10f\n", x) // 小数点を10桁まで表示
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;

int POWINT(int x, int n) {
  int ret = 1;
  rep(i, 0, n) ret *= x;
  return ret;
};

ll POWLL(int x, int n) {
  ll ret = 1;
  rep(i, 0, n) ret *= x;
  return ret;
};

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

int isPrime(int x) {
  int i;
  if (x < 2) return 0;
  else if (x == 2) return 1;

  if (x % 2 == 0) return 0;
  for (i = 3; i*i <= x; i += 2) {
    if (x % i == 0) return 0;
  }
  return 1;
};

static const int MAX = 100005;

bool check(int x) {
  if (x % 2 == 0) {
    return false;
  }
  return (isPrime(x) && isPrime((x+1)/2));
};

int main() {
  int Q;
  cin >> Q;
  int l, r;

  vector<int> A;

  rep(i, 1, MAX) {
    if (check(i)) {
      A.pb(i);
    }
  }

  rep(i, 0, Q) {
    cin >> l >> r;
    int llidx = lbidx(A, l);
    int rlbidx = lbidx(A, r);
    int dis = rlbidx - llidx;
    if (r == A[rlbidx]) {
      dis++;
    }

    cout << max(0, dis) << endl;
  }

  return 0;
};
