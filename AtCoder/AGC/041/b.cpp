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

bool check(int mid, vector<int> &a, int n, int p, int v, int m) { // 問題セットになる可能性がある
  if (n - mid <= p) return true;
  if (a[mid] + m < a[n-p]) return false;
  {
    ll score =  (ll)a[mid] + (ll)m;
    ll mv = (ll)m * (ll)v;
    ll possible_mv = 0ll;
    possible_mv += (ll)(mid+1) * (ll)m;
    possible_mv += (ll)(p-1) * (ll)m;
    rep(i, mid+1, n-p+1) {
      possible_mv += (score - (ll)a[i]); // (score - (ll)a[i])はm以下が保証されている
    }
    if (possible_mv >= mv) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, v, p;
  cin >> n >> m >> v >> p;

  vector<int> a(n);

  rep(i, 0, n) {
    cin >> a[i];
  }

  sort(All(a));

  int low = -1; // ng
  int high = n-1; // ok

  while (abs(high - low) > 1) {
    int mid = (high + low) / 2;
    if (check(mid, a, n, p, v, m)) {
      high = mid;
    } else {
      low = mid;
    }
  }

  cout << n - high << endl;

  return 0;
};
