#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define ld long double
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
#define debug(x) cerr << #x << ": " << (x) << "\n";

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<int>>> vvvl;
typedef vector<PI> vpi;
typedef vector<vector<PI>> vvpi;
typedef vector<vector<vector<PI>>> vvvpi;
typedef vector<PLL> vpl;
typedef vector<vector<PLL>> vvpl;
typedef vector<vector<vector<PLL>>> vvvpl;

int POWINT(int x, int n) {
  int ret = 1;
  rep(i, 0, n) ret *= x;
  return ret;
};

ll POWLL(ll x, int n) {
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

int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1}; // ul, u, ur, r, dr, d, dl, l
int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h, w;
  cin >> h >> w;
  vvi after(h, vi(w)), recover(h, vi(w)), after2(h, vi(w));

  char ch;
  rep(i, 0, h) {
    rep(j, 0, w) {
      cin >> ch;
      if (ch == '#') {
        after[i][j] = 1;
        recover[i][j] = 1;
      } else {
        after[i][j] = 0;
        recover[i][j] = 0;
      }
    }
  }

  rep(i, 0, h) {
    rep(j, 0, w) {
      if (after[i][j] == 0) {
        rep(k, 0, 8) {
          int y = i + dy[k];
          int x = j + dx[k];
          if (0 <= x && x < w && 0 <= y && y < h) {
            recover[y][x] = 0;
          }
        }
      }
    }
  }

  rep(i, 0, h) {
    rep(j, 0, w) {
      after2[i][j] = recover[i][j];
    }
  }

  rep(i, 0, h) {
    rep(j, 0, w) {
      if (recover[i][j] == 1) {
        rep(k, 0, 8) {
          int y = i + dy[k];
          int x = j + dx[k];
          if (0 <= x && x < w && 0 <= y && y < h) {
            after2[y][x] = 1;
          }
        }
      }
    }
  }

  bool ok = true;
  rep(i, 0, h) {
    rep(j, 0, w) {
      if (after[i][j] == after2[i][j]) continue;
      ok = false;
      break;
    }
    if (ok) continue;
    break;
  }

  if (ok) {
    cout << "possible" << endl;
    rep(i, 0, h) {
      rep(j, 0, w) {
        if (recover[i][j] == 1) {
          cout << '#';
        } else {
          cout << ".";
        }
      }
      cout << endl;
    }
  } else {
    cout << "impossible" << endl;
  }

  return 0;
};
