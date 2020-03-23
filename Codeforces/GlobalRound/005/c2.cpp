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

const int D = 3;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<vector<int>> p(n, vector<int> (D));
  rep(i, 0, n)  {
    rep(j, 0, D) {
      cin >> p[i][j];
    }
  }

  auto Solve = [&](auto &Self, vector<int> ids, int k) { // ids: id配列, k: dimension
    if (k == D) {
      return ids[0];
    }

    map<int, vector<int>> mp;

    for (int x: ids) {
      mp[p[x][k]].pb(x); // idがxのk軸座標を、keyとしてidを追加
    }

    vector<int> a;
    for (auto &q: mp) {
      int cur = Self(Self, q.second, k + 1);
      if (cur != -1) {
        a.pb(cur);
      }
    }

    for (int i = 0; i + 1 < (int) a.size(); i+= 2) {
      cout << a[i] + 1 << " " << a[i+1] + 1 << endl;
    }

    return (a.size() % 2 == 1 ? a.back() : -1);
  };

  vector<int> t(n);
  iota(All(t), 0);
  Solve(Solve, t, 0);

  return 0;
};
