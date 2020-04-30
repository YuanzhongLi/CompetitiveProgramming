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
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << "\n";
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define endl "\n"
// gcj print用
#define Case(x) printf("Case #%d: ", x);

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
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
};

ll POWLL(ll x, int n) {
  ll ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
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
vector<int> baseNumberLL(ll N, int digits, ll x) {
  vector<int> ret(digits, 0);
  // 商
  ll quotient = x;
  int counter = 0;
  while (quotient) {
    // 余り
    ll remainder = quotient % (int)N;
    quotient /= N;
    ret[counter] = (int)remainder;
    counter++;
  }

  return ret;
};

ll T[10] = {0, 1, 2, 3, 4, 4, 5, 6, 7, 8};

ll dp1[20], dp2[20];

ll solve(ll x) {
  if (x == 0) return 1ll;
  auto vec = baseNumberLL(10ll, 20, x);
  while (vec.back() == 0) vec.pop_back();
  reverse(All(vec));

  rep(i, 0, 20) {
    dp1[i] = dp2[i] = 0ll;
  }

  dp2[0] = 1;

  rep(i, 0, vec.size()) {
    int num = vec[i];
    dp1[i+1] = dp1[i] * 8ll + dp2[i] * T[num];

    if (num == 4 || num == 9) {
      dp2[i+1] = 0ll;
    } else {
      dp2[i+1] = dp2[i];
    }
  }

  return dp1[vec.size()] + dp2[vec.size()];
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll a, b;
  cin >> a >> b;
  a--;

  ll A = solve(a);
  ll B = solve(b);

  cout << (b - (a+1ll) + 1ll) - (B - A) << endl;

  return 0;
};
