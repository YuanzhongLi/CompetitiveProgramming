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

const int MX = 2005;
bool d[3][3][MX]; // [最初の文字列][次の文字列][ずれ幅]

int main() {
  vector<string> s(3);
  rep(i, 0, 3) {
    cin >> s[i];
  }

  sort(All(s));
  int ans = MX * 3;

  do {
    rep(i, 0, 3) {
      rep(j, 0, 3) {
        if (i >= j) continue;
        rep(k, 0, s[i].size()) { // 最初の文字列の長さまででいい
          bool ok = true;
          rep(ni, k, s[i].size()) {
            int nj = ni - k;
            if (nj >= s[j].size()) break;
            if (s[i][ni] == '?' || s[j][nj] == '?') continue;
            if (s[i][ni] != s[j][nj]) ok = false;
          }
          d[i][j][k] = ok;
        }
      }
    }

    auto f = [&](int i, int j, int k) {
      if (k >= s[i].size()) return true;
      return d[i][j][k];
    };

    rep(x, 0, MX) {
      rep(y, 0, MX) {
        if (!f(0, 1, x)) continue; // 0,1をxずらしてだめ
        if (!f(1, 2, y)) continue; // 1,2をyずらしてだめ
        if (!f(0, 2, x+y)) continue; // 0,2をx+yずらしてだめ
        int now = 0;
        // 右端が2の文字列とは限らない!
        now = max<int>(now, s[0].size());
        now = max<int>(now, x+s[1].size());
        now = max<int>(now, x+y+s[2].size());
        ans = min(ans, now);
      }
    }
  } while (next_permutation(All(s)));

  cout << ans << endl;

  return 0;
};
