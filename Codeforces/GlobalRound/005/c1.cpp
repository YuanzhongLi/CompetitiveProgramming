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

static const ll LINF = 1ll << 55;

struct Point {
  int id;
  ll x, y, z;
};

bool check(Point pi, Point tmp, Point pj) {
  ll min_x = min(pi.x, tmp.x);
  ll max_x = max(pi.x, tmp.x);

  ll min_y = min(pi.y, tmp.y);
  ll max_y = max(pi.y, tmp.y);

  ll min_z = min(pi.z, tmp.z);
  ll max_z = max(pi.z, tmp.z);

  return (min_x <= pj.x && pj.x <= max_x) && (min_y <= pj.y && pj.y <= max_y) && (min_z <= pj.z && pj.z <= max_z);
};

int main() {
  int n;
  cin >> n;
  vector<bool> removed(n, false);

  vector<Point> p(n);
  ll x, y, z;
  rep(i, 0, n) {
    cin >> x >> y >> z;
    p[i] = { i, x, y, z };
  }

  vector<PI> ans;

  rep(i, 0, n - 1) {
    Point pi = p[i];
    ll dis_x = LINF, dis_y = LINF, dis_z = LINF;

    if (removed[i]) continue;

    Point tmp = { -1,  1ll, 1ll, 1ll };

    rep(j, i+1, n) {
      if (removed[j]) continue;
      Point pj = p[j];

      if (tmp.id == -1) {
        tmp = pj;
        continue;
      }
      if (check(pi, tmp, pj)) {
        tmp = pj;
      }
    }
    ans.pb(make_pair(pi.id+1, tmp.id+1));
    removed[tmp.id] = true;
    removed[pi.id] = true;
  }

  for (auto el: ans) {
    cout << el.first << " " << el.second << endl;
  }

  return 0;
};
