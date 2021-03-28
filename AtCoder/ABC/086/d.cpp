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
typedef vector<vector<vector<vector<int>>>> vvvvi;
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

int K;
int get(int x1, int y1, int x2, int y2, vvi &sum) {
  if (!(0 <= x1 && x1 < 2*K && 0 <= y1 && y1 < 2*K && 0 <= x2 && x2 < 2*K && 0 <= y2 && y2 < 2*K)) return 0;

  int ret = sum[x2][y2];
  int a = 0, b = 0, c = 0;
  if (x1 > 0) a = sum[x1-1][y2];
  if (y1 > 0) b = sum[x2][y1-1];
  if (x1 > 0 && y1 > 0) c = sum[x1-1][y1-1];
  return ret - (a+b-c);
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N; cin >> N >> K;
  vvi B(2*K, vi(2*K));
  vvi W(2*K, vi(2*K));
  rep(i, 0, N) {
    int x, y; char c;
    cin >> x >> y >> c;
    if (c == 'B') {
      B[x%(2*K)][y%(2*K)]++;
    }
    if (c == 'W') {
      W[x%(2*K)][y%(2*K)]++;
    }
  }
  rep(i, 0, 2*K) {
    rep(j, 0, 2*K) {
      {
        int a = 0, b = 0, c = 0;
        if (i > 0) a = B[i-1][j];
        if (j > 0) b = B[i][j-1];
        if (i > 0 && j > 0) c = B[i-1][j-1];
        B[i][j] += (a+b-c);
      }
      {
        int a = 0, b = 0, c = 0;
        if (i > 0) a = W[i-1][j];
        if (j > 0) b = W[i][j-1];
        if (i > 0 && j > 0) c = W[i-1][j-1];
        W[i][j] += (a+b-c);
      }
    }
  }

  int ans = 0;
  rep(i, 0, K) {
    rep(j, 0, K) {
      int alt = 0;
      alt = get(0,0,i-1,j-1,B) + get(i,j,i+K-1,j+K-1,B) + get(0,j+K,i-1,2*K-1,B) + get(i+K,0,2*K-1,j-1,B) + get(i+K,j+K,2*K-1, 2*K-1,B);
      alt += get(0,j,i-1,j+K-1,W) + get(i,0,i+K-1,j-1,W) + get(i,j+K,i+K-1,2*K-1,W) + get(i+K,j,2*K-1,j+K-1,W);
      chmax(ans, alt);
    }
  }
  rep(i, 0, K) {
    rep(j, 0, K) {
      int alt = 0;
      alt = get(0,0,i-1,j-1,W) + get(i,j,i+K-1,j+K-1,W) + get(0,j+K,i-1,2*K-1,W) + get(i+K,0,2*K-1,j-1,W) + get(i+K,j+K,2*K-1, 2*K-1,W);

      alt += get(0,j,i-1,j+K-1,B) + get(i,0,i+K-1,j-1,B) + get(i,j+K,i+K-1,2*K-1,B) + get(i+K,j,2*K-1,j+K-1,B);
      chmax(ans, alt);
    }
  }

  cout << ans << endl;


  return 0;
};
