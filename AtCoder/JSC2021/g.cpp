#define LOCAL
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,s,n) for (int i = (ll)s; i < (ll)n; i++)
#define rrep(i,n,e) for (int i = (ll)n; i > (ll)e; i--)
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
// #define M_PI 3.14159265358979323846 // CF
#define deg2rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad2deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)
#define Find(set, element) set.find(element) != set.end()
#define Decimal(x) cout << fixed << setprecision(10) << x << endl; // print Decimal number 10 Rank
#define endl "\n"
#define Case(x) printf("Case #%d: ", x); // gcj

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
typedef vector<PI> vpi;
typedef vector<vector<PI>> vvpi;
typedef vector<PLL> vpl;
typedef vector<vector<PLL>> vvpl;
typedef vector<char> vch;
typedef vector<vector<char>> vvch;

constexpr ll INF = 1001002003004005006ll;
constexpr int n_max = 2e5+10;

template<class T>
inline bool chmax(T &a, T b) { if(a<b) { a=b; return true; } return false; };
template<class T>
inline bool chmin(T &a, T b) { if(a>b) { a=b; return true; } return false; };

template<class T, class U>
T POW(T x, U n) {T ret=1; while (n>0) {if (n&1) {ret*=x;} x*=x; n>>=1;} return ret;};

// debug
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) {return '"' + s + '"';};
string to_string(const char c) {return to_string((string) &c);};
string to_string(bool b) {return (b ? "true" : "false");};
template <size_t N>
string to_string(bitset<N> v){
  string res = "";
  for(size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
  return res;
};
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for(const auto &x : v) {
    if(!first) res += ", ";
    first = false; res += to_string(x);
  }
  res += "}";
  return res;
};
template <typename A, typename B>
string to_string(pair<A, B> p){return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}

void debug_out() {cerr << endl;};
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); };

void LINE_OUT() {
  cout << "--------------" << endl;
};

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define LINE LINE_OUT();
#else
#define debug(...) 71
#define LINE 71;
#endif

void print() { cout << endl; }
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(tail) != 0) cout << " ";
  print(forward<Tail>(tail)...);
};

template <class T>
void print(vector<T> &vec) {
  for (auto& a : vec) {
    cout << a;
    if (&a != &vec.back()) cout << " ";
  }
  cout << endl;
};

template <class T>
void print(vector<vector<T>> &df) {
  for (auto& vec : df) {
    print(vec);
  }
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
  friend constexpr modint modinv(const modint &rhs) noexcept {
    i64 a_ = rhs.a, b = Modulus, u = 1, v = 0;
    while(b){
      i64 t = a_/b;
      a_ -= t * b; swap(a_,b);
      u -= t * v; swap(u,v);
    }
    u %= Modulus;
    if(u < 0) u += Modulus;
    return modint(u);
  };
};

const long long MOD = 1e9+7;
using mint = modint<MOD>;
// iostream
std::ostream &operator<<(std::ostream &out, const modint<MOD> &m) {
  out << m.a; return out;
};
std::istream &operator>>(std::istream &in, modint<MOD> &m) {
  long long a; in >> a; m = mint(a); return in;
};

mint fact[500005];

void init() {
  fact[0] = mint(1);
  for(int i = 1; i < 500005; i++) {
    fact[i] = fact[i-1] * mint(i);
  }
};

// calculate nCr mod
mint modcomb(long long n, long long r) {
  return fact[n] / fact[r] / fact[n - r];
};

// caluculate nPr mod
mint modp(long long n, long long r) {
  return fact[n]/fact[n-r];
};

class Unionfind {
public:
  int N;
  vector<int> par; // parent
  vector<int> rank; // 木の高さ
  vector<int> size; // 節点が属する木の節点数
  int treeNum; // 木の数
  Unionfind(int N) : N(N), par(N), rank(N, 0), size(N, 1) {
    for (int i = 0; i < N; i++) {
      par[i] = i;
    }
    treeNum = N;
  }
  // 節点(木)追加
  void addNode() {
    par.push_back(N);
    rank.push_back(0);
    size.push_back(1);
    N++;
    treeNum++;
  }
  // 根を探すと同時に経路上にある節点の親が根になるように代入
  int root(int x) {
    return par[x] == x ? x : par[x] = root(par[x]);
  }
  // 同じ木に属しているか
  bool same(int x, int y) {
    return root(x) == root(y);
  }
  // rankが低い方の木をrankが高い方の木の根に結びつける(結びつけた後の新しい木の高さが高くなることがないため)
  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) {
      return;
    }
    treeNum--;
    if (rank[x] < rank[y]) {
      par[x] = y;
      size[y] += size[x];
    } else {
      par[y] = x;
      size[x] += size[y];
      if (rank[x] == rank[y]) {
        rank[x] += 1;
      }
    }
  }

  vector<vector<int>> group() { // O(N)
    vector<vector<int>> res;
    vector<vector<int>> table(N);
    for (int i = 0; i < N; i++) {
      table[root(i)].push_back(i);
    }
    for (int i = 0; i < N; i++) {
      if (!table[i].empty()) {
        res.push_back(table[i]);
      }
    }
    return res;
  }
};

vvi graph1;
vector<bool> visited1;
int N;

bool dfs(int u, int p) {
  visited1[u] = true;
  for (int v: graph1[u]) {
    if (v == p) continue;
    if (visited1[v]) return true;
    if (dfs(v, u)) return true;
  }
  return false;
};

vector<bool> visited;
vvpi graph;
vector<vector<mint>> mem;

mint dp(int u, int p) {
  visited[u] = true;
  mint ret = mint(1);
  for (auto pi: graph[u]) {

  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;

  vvi grid(N, vi(N));
  graph1.resize(N);
  visited1.resize(N); rep(i,0,N) visited1[i] = false;

  rep(i,0,N) rep(j,0,N) {
    cin >> grid[i][j];
    if (grid[i][j] == 1) {
      graph1[i].pb(j);
      graph1[j].pb(i);
    }
  }

  bool not_tree = false;
  rep(i,0,N) {
    if (visited1[i]) continue;
    not_tree |= dfs(i, -1);
    if (not_tree) break;
  }
  if (not_tree) {
    cout << 0 << endl; return 0;
  }

  Unionfind uf(N);
  rep(i,0,N) {
    rep(j,0,N) {
      if (grid[i][j] == 1) uf.unite(i, j);
    }
  }

  auto groups = uf.group();
  int M = groups.size();
  vi ntom(N);
  rep(i,0,M) {
    for (int id: groups[i]) {
      ntom[id] = i;
    }
  }

  vvi counter(M, vi(M));

  rep(i,0,N) {
    rep(j,0,N) {
      int i_ = ntom[i], j_ = ntom[j];
      if (i_ == j_) continue;
      if (grid[i][j] == -1) {
        counter[i_][j_]++;
      }
    }
  }

  graph.resize(N);
  rep(i,0,M) {
    rep(j,0,M) {
      int cnt = counter[i][j];
      if (cnt > 0) {
        graph[i].pb({j, cnt});
      }
    }
  }

  visited.resize(M); rep(i,0,M) visited[i] = false;
  mem.resize(M); rep(i,0,M) mem[i].resize(M);


  return 0;
};
