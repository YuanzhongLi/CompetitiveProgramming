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

template<std::int_fast64_t Modulus>
class modint {
  using i64 = int_fast64_t;

  public:
  i64 a;

  constexpr modint(const i64 x = 0) noexcept {
    this -> a = x % Modulus;
    if(a < 0){
      a += Modulus;
    }
  }
  // constexpr i64 &value() const noexcept {return a;}
  constexpr const i64 &value() const noexcept {return a;}
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if(a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if(a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
    i64 a_ = rhs.a, b = Modulus, u = 1, v = 0;
    while(b){
      i64 t = a_/b;
      a_ -= t * b; swap(a_,b);
      u -= t * v; swap(u,v);
    }
    a = a * u % Modulus;
    if(a < 0) a += Modulus;
    return *this;
  }

  // 自前実装
  constexpr bool operator==(const modint rhs) noexcept {
    return a == rhs.a;
  }
  constexpr bool operator!=(const modint rhs) noexcept {
    return a != rhs.a;
  }
  constexpr bool operator>(const modint rhs) noexcept {
    return a > rhs.a;
  }
  constexpr bool operator>=(const modint rhs) noexcept {
    return a >= rhs.a;
  }
  constexpr bool operator<(const modint rhs) noexcept {
    return a < rhs.a;
  }
  constexpr bool operator<=(const modint rhs) noexcept {
    return a <= rhs.a;
  }
  // constexpr modint& operator++() noexcept {
  //     return (*this) += modint(1);
  // }
  // constexpr modint operator++(int) {
  //     modint tmp(*this);
  //     operator++();
  //     return tmp;
  // }
  // constexpr modint& operator--() noexcept {
  //     return (*this) -= modint(1);
  // }
  // constexpr modint operator--(int) {
  //     modint tmp(*this);
  //     operator--();
  //     return tmp;
  // }
  template<typename T>
  friend constexpr modint modpow(const modint &mt, T n) noexcept {
    if(n < 0){
      modint t = (modint(1) / mt);
      return modpow(t, -n);
    }
    modint res = 1, tmp = mt;
    while(n){
      if(n & 1)res *= tmp;
      tmp *= tmp;
      n /= 2;
    }
    return res;
  }
};

const ll MOD = 1e9+7;
using mint = modint<MOD>;
// 標準入出力対応
std::ostream &operator<<(std::ostream &out, const modint<MOD> &m) {
  out << m.a;
  return out;
}
std::istream &operator>>(std::istream &in, modint<MOD> &m) {
  ll a;
  in >> a;
  m = mint(a);
  return in;
}

mint T[100005];
void init_T() {
  T[0] = mint(1);
  rep(i, 1, 100005) {
    T[i] = T[i-1]*mint(3);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string S;
  cin >> S;
  int n = S.size();
  vector<mint> l_A_sum(n), r_C_sum(n), l_D_sum(n), r_D_sum(n);
  rep(i, 0, n) {
    char ch = S[i];
    if (ch == 'A') {
      l_A_sum[i] += mint(1);
    }
    if (ch == '?') {
      l_D_sum[i] += mint(1);
    }
    if (i > 0) {
      l_A_sum[i] += l_A_sum[i-1];
      l_D_sum[i] += l_D_sum[i-1];
    }
  }

  init_T();

  for (int i = n-1; i >= 0; i--) {
    char ch = S[i];
    if (ch == 'C') {
      r_C_sum[i] += mint(1);
    }
    if (ch == '?') {
      r_D_sum[i] += mint(1);
    }
    if (i < n-1) {
      r_C_sum[i] += r_C_sum[i+1];
      r_D_sum[i] += r_D_sum[i+1];
    }
  }

  mint ans = 0;
  rep(i, 1, n-1) {
    char ch = S[i];
    if (ch == 'B' || ch == '?') {
      mint a = l_A_sum[i-1];
      mint c = r_C_sum[i+1];
      mint dl = l_D_sum[i-1];
      mint dr = r_D_sum[i+1];
      if (dl.a > 0 && dr.a > 0) {
        ans += a * c * T[dl.a + dr.a];
        ans += a * dr * T[dl.a + dr.a - 1];
        ans += dl * c * T[dl.a + dr.a - 1];
        ans += dl * dr * T[dl.a + dr.a - 2];
      } else if (dl.a > 0) { // dr == 0
        ans += a * c * T[dl.a + dr.a];
        ans += dl * c * T[dl.a + dr.a - 1];
      } else if (dr.a > 0) { // dl == 0
        ans += a * c * T[dl.a + dr.a];
        ans += a * dr * T[dl.a + dr.a - 1];
      } else { // dl == dr == 0
        ans += a * c * T[dl.a + dr.a];
      }
    }
  }

  cout << ans << endl;

  return 0;
};
