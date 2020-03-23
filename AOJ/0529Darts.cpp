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

bool check(ll x, set<ll> &s) { // x以上が作れるかどうか
  bool ret = false;
  for (auto it: s) {
    if (Find(s, x - it)) {
      ret = true;
      break;
    }
  }

  return ret;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  int m;
  while (cin >> n >> m, n) {
    set<int> s;
    vector<int> P(n+1, 0);
    rep(i, 1, n+1) {
      cin >> P[i];
    }

    sort(All(P));

    rep(i, 0, n+1) {
      rep(j, i, n+1) {
        s.insert(P[i]+P[j]);
      }
    }

    vector<int> possible; // 二本の矢での取り得る点数
    for (auto it: s) {
      possible.pb(it);
    }
    sort(All(possible)); // (N^2long(N^2))

    int ans = 0;

    rep(i, 0, n+1) {
      int a = P[i];
      rep(j, i, n+1) {
        int b = P[j];
        int ab = a+b;
        if (ab > m) break;

        int ng = possible.size();
        int ok = 0;
        while (abs(ng - ok) > 1) {
          ll mid = (ok + ng) / 2;
          if (possible[mid] <= (m - ab)) {
            ok = mid;
          } else {
            ng = mid;
          }
        }

        ans = max(ans, possible[ok] + ab);
      }
    }

    cout << ans << endl;
  }


  return 0;
};
