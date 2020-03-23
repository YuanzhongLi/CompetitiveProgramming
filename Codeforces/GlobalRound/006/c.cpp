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

ll T[505][505];

ll lcm(ll a, ll b) {
  ll gcd = __gcd(a, b);
  return a / gcd * b;
};

void make(int r, int c) {
  int tmpr = r;
  int tmpc = c;
  vector<ll> R(505);
  vector<ll> C(505);
  ll cnt = 1ll;
  int c_idx = 1;
  int r_idx = 1;
  while (r > 0 || c > 0) {
    if (c > 0) {
      C[c_idx] = cnt;
      cnt++;
      c_idx++;
      c--;
    }
    if (r > 0) {
      R[r_idx] = cnt;
      cnt++;
      r_idx++;
      r--;
    }
  }

  // rep(i, 1, tmpr+1) {
  //   cout << R[i] << endl;
  // }
  // cout << "----" << endl;
  // rep(i, 1, tmpc+1) {
  //   cout << C[i] << endl;
  // }
  // cout << "-----" << endl;

  R[1] = 4ll;
  R[2] = 1ll;
  C[1] = 2ll;
  C[2] = 3ll;

  rep(i, 1, tmpr+1) {
    rep(j, 1, tmpc+1) {
      T[i][j] = lcm(R[i], C[j]);
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int r, c;
  cin >> r >> c;
  if (r == 1 && c == 1) {
    cout << 0 << endl;
  } else if (r == 1) {
    rep(i, 1, c+1) {
      cout << i+1;
      if (i < c) {
        cout << ' ';
      }
    }
    cout << endl;
  } else if (c == 1) {
    rep(i, 1, r+1) {
      cout << i+1 << endl;
    }
  } else {
    make(r, c);
    // ll ma = 0ll;
    // rep(i, 0, 505) {
    //   rep(j, 0, 505) {
    //     ma = max(ma, T[i][j]);
    //   }
    // }
    // cout << ma << endl;
    rep(i, 1, r+1) {
      rep(j, 1, c+1) {
        cout << T[i][j];
        if (j < c) cout << ' ';
      }
      cout << endl;
    }
  }
  return 0;
};
