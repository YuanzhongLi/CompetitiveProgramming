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

char T[2] = { '+', '-' };

int main() {
  string s;
  cin >> s;
  int A = s[0] - '0', B = s[1] - '0', C = s[2] - '0', D = s[3] - '0';
  rep(op1, 0, 2) {
    rep(op2, 0, 2) {
      rep(op3, 0, 2) {
        int ret = A;
        if (op1 == 0) {
          ret += B;
        } else if (op1 == 1) {
          ret -= B;
        }

        if (op2 == 0) {
          ret += C;
        } else if (op2 == 1) {
          ret -= C;
        }

        if (op3 == 0) {
          ret += D;
        } else if (op3 == 1) {
          ret -= D;
        }

        if (ret == 7) {
          cout << A << T[op1] << B << T[op2] << C << T[op3] << D << "=7" << endl;
          return 0;
        }
      }
    }
  }
};
