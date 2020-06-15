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

void LINE_OUT() {
  cout << "--------------" << endl;
};

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
#define LINE LINE_OUT();
#else
#define debug(...) 71
#define print(...) 71
#define LINE 71;
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int H, W, K; cin >> H >> W >> K;
  int x1, y1, x2, y2; cin >> y1 >> x1 >> y2 >> x2;
  x1--; y1--; x2--; y2--;

  vvch grid(H, vch(W));
  rep(i, 0, H) rep(j, 0, W) cin >> grid[i][j];

  int s = y1*W+x1, e = y2*W+x2;
  vi dist(H*W, INF);
  vector<bool> visited(H*W, false);
  dist[s] = 0;

  queue<int> q;
  q.push(s);

  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (visited[u]) continue;
    visited[u] = true;

    int uy = u / W;
    int ux = u % W;

    { // north
      for (int i = uy-1; i >= max(0, uy-K); i--) {
        int v = i*W+ux;
        if (dist[v] <= dist[u] || grid[i][ux] == '@') break;
        dist[v] = dist[u]+1;
        q.push(v);
      }
    }

    { // south
      for (int i = uy+1; i <= min(H-1, uy+K); i++) {
        int v = i*W+ux;
        if (dist[v] <= dist[u] || grid[i][ux] == '@') break;
        dist[v] = dist[u]+1;
        q.push(v);
      }
    }

    { // east
      for (int i = ux+1; i <= min(W-1, ux+K); i++) {
        int v = uy*W+i;
        if (dist[v] <= dist[u] || grid[uy][i] == '@') break;
        dist[v] = dist[u]+1;
        q.push(v);
      }
    }

    { // west
      for (int i = ux-1; i >= max(0, ux-K); i--) {
        int v = uy*W+i;
        if (dist[v] <= dist[u] || grid[uy][i] == '@') break;
        dist[v] = dist[u]+1;
        q.push(v);
      }
    }

    LINE;
  }


  if (dist[e] == INF) {
    cout << -1 << endl;
  } else {
    cout << dist[e] << endl;
  }


  return 0;
};
