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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int q;
  cin >> q;
  rep(Q, 0, q) {
    int n;
    cin >> n;
    vector<int> A(n+1);
    rep(i, 0, n) {
      cin >> A[i];
    }

    A[n] = A[0];

    int types = 1;
    bool span_flag = false;
    rep(i, 0, n) {
      if (A[i] != A[i+1]) {
        types = 2;
      } else {
        span_flag = true;
      }
    }

    if (types == 1) { // 全部同じ
      cout << 1 << endl;
      rep(i, 0, n) {
        cout << 1;
        if (i < n - 1) {
          cout << " ";
        }
      }
      cout << endl;
      continue;
    }

    vector<int> ans(n+1);
    ans[0] = ans[n] = 1;
    int c = 1;
    rep(i, 0, n) {
      ans[i] = c;
      if (A[i] != A[i+1]) {
        if (c == 1) {
          c = 2;
        } else {
          c = 1;
        }
      }
    }

    if (A[n-1] != A[n] && ans[n-1] == ans[n]) {
      if (span_flag) { // 1, 2のみに抑えられる
        int bc = 1;
        for (int i = n; i > 0; i--) {
          ans[i] = bc;
          if (A[i] != A[i-1]) {
            if (bc == 1) {
              bc = 2;
            } else {
              bc = 1;
            }
          } else {
            break;
          }
        }

        cout << 2 << endl;
        rep(i, 0, n) {
          cout << ans[i];
          if (i < n - 1) {
            cout << " ";
          }
        }
        cout << endl;
      } else {
        ans[n-1] = 3;
        cout << 3 << endl;
        rep(i, 0, n) {
          cout << ans[i];
          if (i < n - 1) {
            cout << " ";
          }
        }
        cout << endl;
      }
    } else {
      cout << 2 << endl;
      rep(i, 0, n) {
        cout << ans[i];
        if (i < n - 1) {
          cout << " ";
        }
      }
      cout << endl;
    }
  }
  return 0;
};
