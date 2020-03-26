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

vector<PI> statement[16];

bool check(vector<int> T) {
  set<int> s;
  for (int p: T) {
    s.insert(p);
  }
  for (int p: T) {
    for (PI pi: statement[p]) {
      if (pi.second == 0) {
        if (Find(s, pi.first)) {
          return false;
        }
      }
      if (pi.second == 1) {
        if (!(Find(s, pi.first))) {
          return false;
        }
      }
    }
  }

  return true;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  rep(i, 0, n) {
    int A;
    cin >> A;
    int x, y;
    rep(j, 0, A) {
      cin >> x >> y;
      x--;
      statement[i].pb(make_pair(x, y));
    }
  }

  int ans = 0;
  rep(i, 0, 1 << n) {
    vector<int> T;
    rep(j, 0, n) { // j人目が正直者かどうか
      if ((i >> j) & 1 == 1) {
        T.pb(j);
      }
    }
    // cout << "print: ";
    // PrintVec(T);
    if (T.empty()) continue;

    if (check(T)) {
      ans = max(ans, (int)T.size());
    }
  }

  cout << ans << endl;

  return 0;
};
