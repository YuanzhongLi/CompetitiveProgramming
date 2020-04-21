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

int digit(int n) {
  for (int i = 5; i >= 0; i--) {
    if (n / POWINT(10, i) > 0) return i+1;
  }
  return 0;
};

int back(vi vec) {
  int ret = 0;
  for (int i = vec.size()-1; i >= 0; i--) {
    ret += vec[i] * POWINT(10, i);
  }
  return ret;
};

vvi solve(int N) {
  vvi N_T(N+1);
  rep(i, 1, N+1) {
    int i_digit = digit(i);
    vi base_i = baseNumber(10, i_digit, i);
    N_T[i] = base_i;
  }

  vvi ret(10, vi (10, 0));

  rep(top, 1, 10) {
    rep(bot, 1, 10) {
      rep(i, 1, N+1) {
        if (N_T[i][0] == top && N_T[i][N_T[i].size()-1] == bot) {
          ret[top][bot]++;
        }
      }
    }
  }

  return ret;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N; cin >> N;

  vvi T = solve(N);

  int ans = 0;

  rep(a, 1, N+1) {
    int a_digit = digit(a);
    vi a_base = baseNumber(10, a_digit, a);
    int top = a_base[0];
    int bot = a_base[a_digit-1];
    ans += T[bot][top];
  }

  cout << ans << endl;

  return 0;
};
