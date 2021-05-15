// #define LOCAL
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

/* SegTreeLazy<X,M>(n,fx,fa,fm,ex,em): モノイド(集合X, 二項演算fx,fa,fm, 単位元ex,em)についてサイズnで構築
    set(int i, X x), build(): i番目の要素をxにセット。まとめてセグ木を構築する。O(n)
    update(i,x): i 番目の要素を x に更新。O(log(n))
    query(a,b):  [a,b) 全てにfxを作用させた値を取得。O(log(n))
    fx: X × X → X
    fa: X × M → X
    fm: M × M → M
    ex: モノイドXでの単位元
    em: モノイドMでの単位元
*/
template <typename X, typename M>
struct LazySegmentTree {
  using FX = function<X(X, X)>;
  using FA = function<X(X, M)>;
  using FM = function<M(M, M)>;
  int n;
  FX fx;
  FA fa;
  FM fm;
  const X ex;
  const M em;
  vector<X> dat;
  vector<M> lazy;
  LazySegmentTree(int n_, FX fx_, FA fa_, FM fm_, X ex_, M em_)
    : n(), fx(fx_), fa(fa_), fm(fm_), ex(ex_), em(em_), dat(n_ * 4, ex), lazy(n_ * 4, em) {
    int x = 1;
    while (n_ > x) x *= 2;
    n = x;
  }

  void set(int i, X x) { dat[i + n - 1] = x; }
  void build() {
    for (int k = n - 2; k >= 0; k--) dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
  }

  /* lazy eval */
  void eval(int k) {
    if (lazy[k] == em) return;  // 更新するものが無ければ終了
    if (k < n - 1) {            // 葉でなければ子に伝搬
      lazy[k * 2 + 1] = fm(lazy[k * 2 + 1], lazy[k]);
      lazy[k * 2 + 2] = fm(lazy[k * 2 + 2], lazy[k]);
    }
    // 自身を更新
    dat[k] = fa(dat[k], lazy[k]);
    lazy[k] = em;
  }

  void update(int a, int b, M x, int k, int l, int r) {
    eval(k);
    if (a <= l && r <= b) {  // 完全に内側の時
      lazy[k] = fm(lazy[k], x);
      eval(k);
    } else if (a < r && l < b) {                   // 一部区間が被る時
      update(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
      update(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
      dat[k] = fx(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
  }
  void update(int a, int b, M x) { update(a, b, x, 0, 0, n); }

  X query_sub(int a, int b, int k, int l, int r) {
    eval(k);
    if (r <= a || b <= l) {  // 完全に外側の時
      return ex;
    } else if (a <= l && r <= b) {  // 完全に内側の時
      return dat[k];
    } else {  // 一部区間が被る時
      X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
      X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
      return fx(vl, vr);
    }
  }
  X query(int a, int b) { return query_sub(a, b, 0, 0, n); }

  /* debug */
  inline X operator[](int a) { return query(a, a + 1); }
  void print() {
    for (int i = 0; i < n; ++i) {
      cout << (*this)[i];
      if (i != n) cout << ", ";
    }
    cout << endl;
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int W, N; cin >> W >> N;

  auto fx = [](int x1, int x2) -> int { return max(x1, x2); };
  auto fa = [](int x, int m) -> int { return m; };
  auto fm = [](int m1, int m2) -> int {return m2; };
  int ex = -INF;
  int em = -INF;
  LazySegmentTree<int, int> lst(W, fx, fa, fm, ex, em);
  rep(i,0,W) lst.set(i, 0);
  lst.build();
  rep(i,0,N) {
    int l, r; cin >> l >> r; l--; r--;
    int h = lst.query(l, r+1)+1;
    cout << h << endl;
    lst.update(l, r+1, h);
  }

  return 0;
};
