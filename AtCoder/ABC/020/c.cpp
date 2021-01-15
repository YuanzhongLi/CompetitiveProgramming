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

ll H, W, T;
vvch grid(10, vch(10));
vvpl graph;
int dy[4] = {-1, 0, 0, 1}; // u, r, l, d
int dx[4] = {0, 1, -1, 0};

tuple<ll, ll> make_graph(ll cost) {
  graph.clear();
  graph.resize(H*W);
  ll s, g;
  rep(i, 0, H*W) {
    int y = i / W, x = i % W;
    if (grid[y][x] == 'S') s = i;
    if (grid[y][x] == 'G') g = i;
    rep(j, 0, 4) {
      int y_ = y+dy[j], x_ = x+dx[j];
      if (0 <= y_ && y_ < H && 0 <= x_ && x_ < W) {
        int to = y_*W+x_;
        if (grid[y_][x_] == '#') {
          graph[i].pb(make_pair(to, cost));
        } else {
          graph[i].pb(make_pair(to, 1));
        }
      }
    }
  }
  return {s, g};
};

ll dijkstra(ll s, ll g) {
  ll n = graph.size();
  vi visited(n, 0);
  vl dist(n, LINF);

  dist[s] = 0;
  priority_queue<PLL> pq;
  pq.push(make_pair(0ll, s));

  while (!pq.empty()) {
    auto f = pq.top(); pq.pop();
    int u = f.second;
    if (visited[u]) continue;
    visited[u] = 1;

    for (auto &f_: graph[u]) {
      int v = f_.first;
      if (visited[v]) continue;
      if (dist[v] > dist[u] + f_.second) {
        dist[v] = dist[u] + f_.second;
        pq.push(make_pair(dist[v] * (-1ll), v));
      }
    }
  }

  return dist[g];
};

void solve(ll T) {
  ll ok = 1, ng = T+1;
  ll s, g;
  while (abs(ok-ng) > 1) {
    ll mid = (ok+ng)/2;
    tie(s, g) = make_graph(mid);
    ll dis = dijkstra(s, g);
    if (dis <= T) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
};



int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> H >> W >> T;
  rep(i, 0, H) rep(j, 0, W) cin >> grid[i][j];
  solve(T);

  return 0;
};
