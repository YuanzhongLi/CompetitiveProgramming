#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (ll)s; i < (ll)n; i++)
#define ll long long
#define ld long double
#define pb push_back
#define All(x) x.begin(), x.end()
#define Find(s, e) set.find(e) != s.end()

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<PI> vpi;
typedef vector<vector<PI>> vvpi;
typedef vector<PLL> vpl;
typedef vector<vector<PLL>> vvpl;
typedef vector<char> vch;
typedef vector<vector<char>> vvch;

constexpr ll LINF = 1001001001001001001ll;
constexpr int INF = 1001001001;

template<class T>
inline bool chmax(T &a, T b) { if(a < b) { a = b; return true; } return false; };
template<class T>
inline bool chmin(T &a, T b) { if(a > b) { a = b; return true; } return false; };

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

const long long MOD = 998244353;
using mint = modint<MOD>;
// iostream
std::ostream &operator<<(std::ostream &out, const modint<MOD> &m) {
  out << m.a; return out;
};
std::istream &operator>>(std::istream &in, modint<MOD> &m) {
  long long a; in >> a; m = mint(a); return in;
};

vector<mint> mem(5005);
void init_mem() {
  mem[0] = mint(1);
  rep(i, 1, mem.size()) {
    mem[i] = mem[i-1];
    mem[i] *= mint(3);
  }
};

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int H, W, K; cin >> H >> W >> K;
  vvch grid(H, vch(W, ' '));
  rep(i, 0, K) {
    int h, w; cin >> h >> w; h--; w--;
    char c; cin >> c;
    grid[h][w] = c;
  }

  init_mem();

  vvi row_f(H, vi(W));
  vvi col_f(W, vi(H));

  rep(i, 0, H) {
    for (int j = W-2; j >= 0; j--) {
      row_f[i][j] = row_f[i][j+1];
      if (grid[i][j+1] == ' ') row_f[i][j]++;
    }
  }

  rep(i, 0, W) {
    for (int j = H-2; j >= 0; j--) {
      col_f[i][j] = col_f[i][j+1];
      if (grid[j+1][i] == ' ') col_f[i][j]++;
    }
  }

  vector<vector<mint>> dp(H, vector<mint>(W, mint(0)));
  dp[0][0] = mint(1);
  int dy[2] = {-1, 0};
  int dx[2] = {0, -1};

  rep(x, 0, W) {
    rep(y, 0, H) {
      rep(i, 0, 2) {
        int uy = y+dy[i], ux = x+dx[i];
        if (0 <= uy && uy < H && 0 <= ux && ux < W) {
          if (i == 0) {
            if (grid[uy][ux] == 'D' || grid[uy][ux] == 'X') {
              dp[y][x] += dp[uy][ux] * mem[row_f[uy][ux]];
            } else if (grid[uy][ux] == ' ') {
              dp[y][x] += mint(2)*(dp[uy][ux] * mem[row_f[uy][ux]]);
            }
          } else {
            if (grid[uy][ux] == 'R' || grid[uy][ux] == 'X') {
              dp[y][x] += dp[uy][ux] * mem[col_f[ux][uy]];
            } else if (grid[uy][ux] == ' ') {
              dp[y][x] += mint(2)*(dp[uy][ux] * mem[col_f[ux][uy]]);
            }
          }
        }
      }
    }
  }

  if (grid[H-1][W-1] == ' ') {
    dp[H-1][W-1] *= 3;
  }

  cout << dp[H-1][W-1] << endl;


  return 0;
};
