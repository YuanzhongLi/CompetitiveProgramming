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
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  vector<PI> s(k);
  vector<PI> e(k);
  int maup = 0;
  int madown = 0;
  int maright = 0;
  int maleft = 0;
  int x, y;
  rep(i, 0, k) {
    cin >> x >> y;
    s[i] = make_pair(x, y);
  }
  rep(i, 0, k) {
    cin >> x >> y;
    e[i] = make_pair(x, y);
  }
  int sx, sy, ex, ey;
  rep(i, 0, k) {
    sx = s[i].first;
    sy = s[i].second;
    ex = e[i].first;
    ey = e[i].second;
  }

  string ans = "";
  rep(i, 0, n-1) {
    ans += "D";
  }
  rep(i, 0, m-1) {
    ans += "L";
  }
  rep(i, 0, m) {
    if (i % 2 == 0) {
      rep(j, 0, n-1) {
        ans += "U";
      }
    } else {
      rep(j, 0, n-1) {
        ans += "D";
      }
    }
    ans += "R";
  }
  cout << (int)ans.length() << endl;
  cout << ans << endl;

  return 0;
};
