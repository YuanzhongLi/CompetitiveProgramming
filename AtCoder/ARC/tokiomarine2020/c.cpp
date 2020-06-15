#define LOCAL
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
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define llbidx(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y) // dist between two elements
// #define M_PI 3.14159265358979323846 // CF
#define deg2rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad2deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)
#define Find(set, element) set.find(element) != set.end()
#define Decimal(x) cout << fixed << setprecision(10) << x << endl; // 小数点を10桁まで表示
#define endl "\n"
#define Case(x) printf("Case #%d: ", x); // gcj

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<PI> vpi;
typedef vector<vector<PI>> vvpi;
typedef vector<PLL> vpl;
typedef vector<vector<PLL>> vvpl;
typedef vector<char> vch;
typedef vector<vector<char>> vvch;

constexpr ll LINF = 1001002003004005006ll;
constexpr int INF = 1001001001;
constexpr int n_max = 2e5+10;

template<class T>
inline bool chmax(T &a, T b) { if(a < b) { a = b; return true; } return false; };
template<class T>
inline bool chmin(T &a, T b) { if(a > b) { a = b; return true; } return false; };

template<class T, class U>
T POW(T x, U n) {T ret = 1; while (n > 0) {if (n & 1) {ret *= x;} x *= x; n >>= 1;} return ret;};

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

void Print() { cout << endl; };
template <class T>
void Print(vector<T> &vec) {
  for (auto& a : vec) {cout << a; if (&a != &vec.back()) cout << " ";}
  cout << endl;
};
template <class T>
void Print(vector<T> &vec, ll k){
   ll n = vec.size();
   k = min(k, n);
   rep(i, 0, k-1) cout << vec[i] << " ";
   cout << vec[k-1] << endl;
};
template <class T>
void Print(vector<vector<T>> &df) {for (auto& vec : df) {print(vec);}};
template<class T, class U>
void Print(pair<T,U> &p){cout << p.first << " " << p.second << endl;};

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define print(...) Print(__VA_ARGS__)
#else
#define debug(...) 71
#define print(...) 71
#endif

struct Node {
  ll value;
  ll lazy;
  Node () {
    value = lazy = 0ll;
  }
};

class LazySegTree {
  int n;
  vector<Node> dat;
  Node e;
public:
  LazySegTree(int n_) {
    n = 1;
    while (n < n_) { n*=2; }
    dat.resize(2*n);
    for (int i = 0; i < 2 * n - 1; i++) {
      dat[i] = e;
    }
  }
  // k番目のノードについて遅延評価を行う
  void eval(int k, int l, int r) {
    if (dat[k].lazy != 0ll) {
      dat[k].value += dat[k].lazy;
      // 最下段かどうかのcheck
      // 子ノードは親ノードの半分を伝播させる
      if (r - l > 1) {
        dat[2*k+1].lazy += dat[k].lazy / 2ll;
        dat[2*k+2].lazy += dat[k].lazy / 2ll;
      }
      dat[k].lazy = 0ll;
    }
  }
  // [a, b)を更新
  void update(int a, int b, ll x, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n;

    // k番目のノードに対して遅延評価を行う
    eval(k, l, r);

    // 範囲外なら何もしない
    if (b <= l || r <= a) return;

    // 完全に覆っているなら、遅延に値を入れた後に評価
    if (a <= l && r <= b) {
      dat[k].lazy += (r - l) * x;
      eval(k, l, r);
    } else { // そうでないならば、子ノードの値を再帰的に計算して、計算済みの値をもらってくる
      update(a, b, x, 2*k+1, l, (l+r)/2);
      update(a, b, x, 2*k+2, (l+r)/2, r);
      dat[k].value = dat[2*k+1].value + dat[2*k+2].value;
    }
  }

  ll query(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n;
    if (b <= l || r <= a) return 0ll;
    // 関数が呼び出されたら評価
    eval(k, l, r);
    if (a <= l && r <= b) return dat[k].value;

    ll vl = query(a, b, 2*k+1, l, (l+r)/2);
    ll vr = query(a, b, 2*k+2, (l+r)/2, r);
    return vl + vr;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K; cin >> N >> K;
  vl memo(n_max);
  rep(i, 1, N+1) cin >> memo[i];

  rep(i, 0, K) {
    vl tmp(n_max, 0);
    rep(j, 1, N+1) {
      ll d = memo[j];
      tmp[max<ll>(1, j-d)]++;
      tmp[min<ll>(N+1, j+d+1)]--;
    }
    rep(j, 2, N+1) {
      tmp[j] += tmp[j-1];
    }
    bool ok = true;
    rep(j, 1, N+1) {
      memo[j] = tmp[j];
      if (memo[j] != N) ok = false;
    };
    if (ok) break;
  }

  rep(i, 1, N+1) {
    cout << memo[i];
    if (i < N) cout << " ";
  }
  cout << endl;

  return 0;
};
