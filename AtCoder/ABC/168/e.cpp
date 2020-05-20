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

void print() {
  cout << endl;
}

template <class T>
void print(vector<T> &vec) {
  for (auto& a : vec) {
    cout << a;
    if (&a != &vec.back()) cout << " ";
  }
  cout << endl;
}

template <class T>
void print(vector<T> &vec, ll k){
   ll n = vec.size();
   k = min(k, n);
   rep(i, 0, k-1) cout << vec[i] << " ";
   cout << vec[k-1] << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
  for (auto& vec : df) {
    print(vec);
  }
}

template<class T, class U>
void print(pair<T,U> &p){
  cout << p.first << " " << p.second << "\n";
}

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

mint fact[200005];

void init() {
  fact[0] = mint(1);
  for(int i = 1; i < 200005; i++) {
    fact[i] = fact[i - 1] * mint(i);
  }
};

// nCr mod を計算する
mint modcomb(long long n, long long r) {
  return fact[n] / fact[r] / fact[n - r];
};

class OBJ {
public:
  ll chi, mom;
  int neg;
  OBJ() {}
  OBJ(ll chi, ll mom, bool neg): chi(chi), mom(mom), neg(neg) {}
  bool operator < (const OBJ &o) const {
    if (neg == o.neg) {
      if (chi == o.chi) {
        return mom < o.mom;
      } else {
        return chi < o.chi;
      }
    } else {
      return neg < o.neg;
    }
  }
};

mint table[200005];

void init_table() {
  table[0] = mint(1);
  rep(i, 1, 200005) {
    table[i] = table[i-1]*mint(2);
  }
};

void Print(OBJ obj) {
  if (obj.neg) cout << "-";
  cout << obj.chi << "/" << obj.mom << endl;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;

  map<OBJ, int> memo;

  int only_one = 0;
  int b_0 = 0, a_0 = 0;

  rep(i, 0, N) {
    ll a, b;
    cin >> a >> b;
    if (a == 0ll && b == 0ll) {
      only_one++;
    } else if (a == 0) {
      a_0++;
    } else if (b == 0) {
      b_0++;
    } else if ((a < 0 && b < 0) || (a > 0 && b > 0)) {
      a = abs(a);
      b = abs(b);
      ll g = __gcd<ll>(a, b);
      memo[OBJ(b/g, a/g, 1)]++;
    } else {
      a = abs(a);
      b = abs(b);
      ll g = __gcd<ll>(a, b);
      memo[OBJ(b/g, a/g, 0)]++;
    }
  }

  init_table();

  int memo_tot = 0;
  for (auto pi: memo) {
    memo_tot += pi.second;
  }

  set<OBJ> done;
  vector<pair<int, int>> V;
  V.pb(make_pair(a_0, b_0));
  for (auto pi: memo) {
    auto obj = pi.first;
    mint i = mint(pi.second);
    OBJ rev_obj = OBJ(obj.mom, obj.chi, (obj.neg == 1 ? 0 : 1));

    if (Find(done, obj)) continue;
    if (Find(done, rev_obj)) continue;

    if (Find(memo, rev_obj)) {
      V.pb(make_pair(memo[obj], memo[rev_obj]));
      done.insert(obj);
      done.insert(rev_obj);
    } else {
      V.pb(make_pair(memo[obj], 0));
    }
  }

  mint ans = mint(1);
  for (auto pi: V) {
    int fi = pi.first, se = pi.second;
    ans *= (table[fi]+table[se]-mint(1));
  }

  ans -= mint(1);

  ans += mint(only_one);
  cout << ans << endl;

  return 0;
};
