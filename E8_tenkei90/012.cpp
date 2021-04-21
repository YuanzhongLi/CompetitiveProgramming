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

vi Data, Rank;

void init(int N) {
  Data.resize(N); rep(i,0,N) Data[i] = i;
  Rank.resize(N); rep(i,0,N) Rank[i] = 1;
};

int root(int x) {
  if (Data[x] == x) return x;
  else return Data[x] = root(Data[Data[x]]);
};

void unite(int a, int b) {
  a = root(a); b = root(b);
  if (a == b) return;
  if (Rank[a] > Rank[b]) {
    Data[b] = a;
  } else if(Rank[a] == Rank[b]) {
    Data[b] = a;
    Rank[a]++;
  } else {
    Data[a] = b;
  }
};

int dy[4] = {-1, 0, 1, 0}; // u, r, d, l
int dx[4] = {0, 1, 0, -1}; // u, r, d, l

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int H, W; cin >> H >> W;
  int N = H*W;
  vvi grid(H, vi(W, 0));
  init(N);

  int Q; cin >> Q;
  while (Q--) {
    int com; cin >> com;
    if (com == 1) {
      int r, c; cin >> r >> c; r--; c--;
      grid[r][c] = 1;
      int a = r*W+c;
      rep(i,0,4) {
        int dr = r+dy[i], dc = c+dx[i];
        if (0 <= dr && dr < H && 0 <= dc && dc < W && grid[dr][dc] == 1) {
          int b = dr*W+dc;
          unite(a, b);
        }
      }
    } else {
      int ra, ca, rb, cb; cin >> ra >> ca >> rb >> cb; ra--; ca--; rb--; cb--;
      int a = ra*W+ca, b = rb*W+cb;
      cout << ((grid[ra][ca] == 1 && grid[rb][cb] == 1 && root(a) == root(b)) ? "Yes" : "No") << endl;
    }
  }

  return 0;
};
