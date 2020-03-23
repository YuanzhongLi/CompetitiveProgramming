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

// 右づめでの10進数xをdigits桁のN進数vectorにしてを返す
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

  reverse(All(ret));

  return ret;
};

void Print(vector<int> &v) {
  for (int n: v) {
    cout << n;
  }
};

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> S(N+1);

  vector<PI> inp(M);
  int P, Y;
  rep(i, 0, M) {
    cin >> P >> Y;
    inp[i].first = P;
    inp[i].second = Y;
    S[P].pb(Y);
  }

  rep(i, 0, N+1) {
    if (!S[i].empty()) {
      sort(All(S[i]));
    }
  }

  rep(i, 0, M) {
    auto PY = inp[i];

    int p = PY.first;
    int y = PY.second;
    auto vec_p = baseNumber(10, 6, p);

    auto vec_y = baseNumber(10, 6, lbidx(S[p], y) + 1);
    Print(vec_p);
    Print(vec_y);
    cout << endl;
  }

  return 0;
};
