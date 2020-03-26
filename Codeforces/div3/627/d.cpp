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

int main() {
  int n;
  cin >> n;
  int a, b;
  vector<PI> topics(n);
  rep(i, 0, n) {
    cin >> topics[i].first;
  }
  rep(i, 0, n) {
    cin >> topics[i].second;
  }

  vector<int> amb(n);
  vector<int> bma(n);

  rep(i, 0, n) {
    int a = topics[i].first;
    int b = topics[i].second;
    amb[i] = a - b;
    bma[i] = b - a;
  }

  // vector<int> ord1(n);
  // iota(All(ord1), 0);
  // vector<int> ord2(n);
  // iota(All(ord2), 0);

  // sort(All(ord1), [&](int a, int b) {
  //   return amb[a] < amb[b];
  // });

  // sort(All(ord2), [&](int a, int b) {
  //   return bma[a] < bma[b];
  // });

  sort(All(amb));
  sort(All(bma));

  ll ans = 0;

  for (int ele: bma) {
    auto it = upper_bound(All(amb), ele);
    if (it == amb.end()) continue;
    int dis = ubidx(amb, ele);
    int num = n - dis;
    // cout << ele << " " << num << endl;
    if (ele < 0) {
      ans += (num - 1);
    } else {
      ans += num;
    }
  }
  cout << ans / 2 << endl;
};

