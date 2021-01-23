// #define LOCAL
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

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

constexpr ll LINF = 1001002003004005006ll;
constexpr int INF = 1002003004;
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

class Matrix {
  public:
  long long r, c;
  vector<vector<long long>> mat;
  Matrix() {}
  Matrix(int r, int c, long long init=0): r(r), c(c) {
    mat.resize(r);
    for (int i=0; i<r; i++) mat[i].resize(c);
    for (int i=0; i<r; i++) for (int j=0; j<c; j++) mat[i][j] = init;
  }
  void show() {
    for (int i=0; i<r; i++) {
      for (int j=0; j<c; j++) {
        cout << mat[i][j]; if (j < c-1) cout << " ";
      }
      cout << endl;
    }
  }
  Matrix operator-() const {
    Matrix ret = Matrix(r, c);
    for (int i=0; i<r; i++) for (int j=0; j<c; j++) ret.mat[i][j] *= -1ll;
    return ret;
  }
  Matrix& operator+=(const Matrix a) {
    assert(r == a.r && c == a.c);
    for (int i=0; i<r; i++) for (int j=0; j<c; j++) mat[i][j] += a.mat[i][j];
    return *this;
  }
  Matrix& operator+=(const int n) {
    for (int i=0; i<r; i++) for (int j=0; j<c; j++) mat[i][j] += n;
    return *this;
  }
  Matrix& operator-=(const Matrix a) {
    assert(r == a.r && c == a.c);
    for (int i=0; i<r; i++) for (int j=0; j<c; j++) mat[i][j] -= a.mat[i][j];
    return *this;
  }
  Matrix& operator-=(const long long n) {
    for (int i=0; i<r; i++) for (int j=0; j<c; j++) mat[i][j] -= n;
    return *this;
  }
  Matrix& operator*=(const Matrix a) {
    assert(c == a.r);
    Matrix ret = Matrix(r, a.c);
    for (int i=0; i<r; i++) for (int k=0; k<c; k++) for (int j=0; j<a.c; j++) ret.mat[i][j] += (mat[i][k] * a.mat[k][j]);
    *this = ret;
    return *this;
  }
  Matrix& operator*=(const long long n) {
    for (int i=0; i<r; i++) for (int j=0; j<c; j++) mat[i][j] *= n;
    return *this;
  }
  Matrix operator+(const Matrix a) const {
    assert(r == a.r && c == a.c);
    return Matrix(*this) += a;
  }
  Matrix operator+(const long long n) const {
    return Matrix(*this) += n;
  }
  Matrix operator-(const Matrix a) const {
    assert(r == a.r && c == a.c);
    return Matrix(*this) -= a;
  }
  Matrix operator-(const long long n) const {
    return Matrix(*this) -= n;
  }
  Matrix operator*(const Matrix a) const {
    return Matrix(*this) *= a;
  }
  Matrix operator*(const long long n) const {
    return Matrix(*this) *= n;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N; cin >> N;
  vl X(N), Y(N);
  rep(i, 0, N) cin >> X[i] >> Y[i];

  int M; cin >> M;
  vector<Matrix> vm(M+1, Matrix(3, 3));
  vm[0].mat[0][0] = vm[0].mat[1][1] = vm[0].mat[2][2] = 1;
  Matrix m1(3, 3), m2(3, 3), m3(3, 3), m4(3, 3);
  m1.mat[0][1] = m1.mat[2][2] = m2.mat[1][0] = m2.mat[2][2] = m3.mat[1][1] = m3.mat[2][2] = m4.mat[0][0] = m4.mat[2][2] = 1;
  m1.mat[1][0] = m2.mat[0][1] = m3.mat[0][0] = m4.mat[1][1] = -1;
  rep(i, 1, M+1) {
    int com; cin >> com;
    if (com == 1) {
      vm[i] = m1 * vm[i-1];
    } else if (com == 2) {
      vm[i] = m2 * vm[i-1];
    } else if (com == 3) {
      ll p; cin >> p;
      m3.mat[0][2] = 2*p;
      vm[i] = m3 * vm[i-1];
    } else {
      ll p; cin >> p;
      m4.mat[1][2] = 2*p;
      vm[i] = m4 * vm[i-1];
    }
  }

  int Q; cin >> Q;
  rep(i, 0, Q) {
    int a, b; cin >> a >> b; b--;
    int x = X[b], y = Y[b];
    Matrix mxy(3, 1);
    mxy.mat[0][0] = x;
    mxy.mat[1][0] = y;
    mxy.mat[2][0] = 1;
    auto ans = vm[a] * mxy;
    cout << ans.mat[0][0] << " " << ans.mat[1][0] << endl;
  }



  return 0;
};
