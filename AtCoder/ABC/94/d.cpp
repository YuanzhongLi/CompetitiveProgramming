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
  int n;
  cin >> n;
  set<int> S;
  S.insert((int)-(1e9+7));
  int a;
  rep(i, 0, n) {
    cin >> a;
    S.insert(a);
  }

  vector<int> A;
  for (auto s: S) {
    A.pb(s);
  }

  int MAX = A[A.size()-1];

  auto it1 = S.lower_bound(MAX/2);
  auto it2 = prev(it1, 1);
  int tmp1 = *it1;
  int tmp2 = *it2;

  if (MAX % 2 == 1) {
    int ok1 = MAX / 2;
    int ok2 = MAX / 2 + 1;
    int dis1_1 = abs(tmp1 - ok1);
    int dis1_2 = abs(tmp1 - ok2);
    int dis2_1 = abs(tmp2 - ok1);
    int dis2_2 = abs(tmp2 - ok2);
    vector<int> ele = { tmp1, tmp1, tmp2, tmp2 };
    vector<int> dis = {dis1_1, dis1_2, dis2_1, dis2_2};
    vector<int> ord(4);
    iota(ord.begin(), ord.end(), 0);

    sort(ord.begin(), ord.end(),  [&](int a, int b) {
      if (dis[a] == dis[b]) return dis[a] > dis[b];
      return dis[a] < dis[b];
    });
    cout << MAX << " " << ele[ord[0]] << endl;
  } else {
    int ok = MAX / 2;
    if (abs(tmp2 - ok) <= abs(tmp1 - ok)) {
      cout << MAX << " " << tmp2 << endl;
    } else {
      cout << MAX << " " << tmp1 << endl;
    }
  }

  return 0;
};
