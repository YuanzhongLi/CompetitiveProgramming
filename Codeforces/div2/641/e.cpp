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

int dx[4] = {0, 1, 0, -1}; // u, r, d, l
int dy[4] = {-1, 0, 1, 0}; // u, r, d, l

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, t; cin >> n >> m >> t;
  vvch grid(n, vch(m));
  rep(i, 0, n) {
    rep(j, 0, m) {
      cin >> grid[i][j];
    }
  }

  vvl table_b(n, vl(m, LINF)), table_w(n, vl(m, LINF));
  queue<int> q_b, q_w;
  int V = n*m;
  vector<bool> visited_b(V, false), visited_w(V, false);
  vi par_b(V, -1), par_w(V, -1);
  rep(y, 0, n) {
    rep(x, 0, m) {
      rep(i, 0, 4) {
        int x_ = x+dx[i];
        int y_ = y+dy[i];
        if (0 <= x_ && x_ < m && 0 <= y_ && y_ < n) {
          if (grid[y][x] == '1' && grid[y][x] == grid[y_][x_]) {
            table_b[y][x] = 1;
            q_b.push(y*m+x);
          }
          if (grid[y][x] == '0' && grid[y][x] == grid[y_][x_]) {
            table_w[y][x] = 1;
            q_w.push(y*m+x);
          }
        }
      }
    }
  }


  while(!q_b.empty()) {
    int u = q_b.front(); q_b.pop();
    if (visited_b[u]) continue;
    visited_b[u] = true;
    int uy = u / m;
    int ux = u % m;

    rep(i, 0, 4) {
      int vy = uy+dy[i];
      int vx = ux+dx[i];
      if (0 <= vx && vx < m && 0 <= vy && vy < n) {
        int v = vy*m+vx;
        if (visited_b[v] || par_b[u] == v) continue;
        par_b[v] = u;
        chmin(table_b[vy][vx], table_b[uy][ux]+1);
        q_b.push(v);
      }
    }
  }

  while(!q_w.empty()) {
    int u = q_w.front(); q_w.pop();
    if (visited_w[u]) continue;
    visited_w[u] = true;
    int uy = u / m;
    int ux = u % m;

    rep(i, 0, 4) {
      int vy = uy+dy[i];
      int vx = ux+dx[i];
      if (0 <= vx && vx < m && 0 <= vy && vy < n) {
        int v = vy*m+vx;
        if (visited_w[v] || par_w[u] == v) continue;
        par_w[v] = u;
        chmin(table_w[vy][vx], table_w[uy][ux]+1);
        q_w.push(v);
      }
    }
  }

  // debug(table_b);
  // debug(table_w);
  rep(i, 0, t) {
    int x, y; cin >> y >> x; x--; y--;
    ll q; cin >> q;
    ll b = table_b[y][x], w = table_w[y][x];
    if (b == LINF && w == LINF) {
      cout << grid[y][x] << endl;
    } else {
      ll mi = min<ll> (b, w);
      if (q < mi) {
        cout << grid[y][x] << endl;
      } else {
        ll tmp = q-mi;
        if (tmp&1ll) {
          if (grid[y][x] == '1') cout << '1' << endl;
          else cout << '0' << endl;
        } else {
          if (grid[y][x] == '1') cout << '0' << endl;
          else cout << '1' << endl;
        }
      }
    }
  }



  return 0;
};
