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

// 左づめでの10進数xをdigits桁のN進数vectorにしてを返す
vector<int> baseNumber(int N, int digits, int x) {
  vector<int> ret(digits, 0);
  // 商
  int quotient = x;
  int counter = 0;
  while (quotient > 0) {
    // 余り
    int remainder = quotient % N;
    quotient /= N;
    ret[counter] = remainder;
    counter++;
  }

  return ret;
};

// 0からn-1までのN進数を上記のbaseNumberで返したvectorのvector
vector<vector<int>> baseNumbers(int n, int N, int digits) {
  vector<vector<int>> ret(n, vector<int> (digits));
  for (int i = 0; i < n; i++) {
    ret[i] = baseNumber(N, digits, i);
  }

  return ret;
};

bool check(vector<int> v, int N) {
  vector<int> tmp_v(v.size());
  rep(i, 0, v.size()) {
    if (v[i] == 0) {
      tmp_v[i] = 3;
    } else if (v[i] == 1) {
      tmp_v[i] = 5;
    } else if (v[i] == 2) {
      tmp_v[i] = 7;
    }
  }
  bool flag3 = false, flag5 = false, flag7 = false;
  ll n = 0;
  rep(i, 0, tmp_v.size()) {
    n += tmp_v[i] * POWLL(10, i);
    if (tmp_v[i] == 3) {
      flag3 = true;
    } else if (tmp_v[i] == 5) {
      flag5 = true;
    } else if (tmp_v[i] == 7) {
      flag7 = true;
    }
  }
  if (flag3 && flag5 && flag7 && n <= N) {
    return true;
  } else {
    return false;
  }
};

int main() {
  int N;
  cin >> N;
  int ans = 0;
  rep(i, 3, 11) {
    auto bs = baseNumbers(POWINT(3, i), 3, i);
    rep(i, 0, bs.size()) {
      // PrintVec(bs[i]);
      if (check(bs[i], N)) {
        ans++;
      }
    }
  }

  cout << ans << endl;
};
