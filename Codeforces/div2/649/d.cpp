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

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 71
#endif

void print() { cout << endl; }
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(tail) != 0) cout << " ";
  print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
  for (auto& a : vec) {
    cout << a;
    if (&a != &vec.back()) cout << " ";
  }
  cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
  for (auto& vec : df) {
    print(vec);
  }
}


vvi graph;
vi used;

int pre_dfs(int now, int pre = -1) { // サイクルがあるかどうか
  used[now] = 1;
  int ret = -1;
  for (int &to: graph[now]) {
    if (to == pre) continue;
    if (used[to]) return to;
    chmax(ret, pre_dfs(to, now));
  }
  return ret; // サイクルに含まれるある点(-1: サイクルなし)
};


vi path;
bool dfs(int s, int now, int pre = -1) { // s始まりのサイクルのパスを求める
  used[now] = 1;
  bool ret = false;
  for (auto &to: graph[now]) {
    if (to == pre) continue;
    if (to == s) {
      path.pb(now);
      return true;
    }
    if (used[to]) continue;
    ret |= dfs(s, to, now);
    if (ret) break;
  }
  if (ret) path.pb(now);
  return ret; // サイクルがあるかどうかを返す
};

vi color;
void c_dfs(int now, int c = 0) {
  color[now] = c;
  used[now] = 1;
  for (auto &to: graph[now]) {
    if (used[to]) continue;
    c_dfs(to, c^1);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, k; cin >> n >> m >> k;
  int half = (k+1)/2;

  graph.resize(n);
  used.resize(n, 0);
  rep(i, 0, m) {
    int a, b; cin >> a >> b;
    a--; b--;
    if (a >= k || b >= k) continue;
    graph[a].pb(b);
    graph[b].pb(a);
  }

  int s = -1;
  rep(i, 0, k) {
    if (!used[i]) chmax(s, pre_dfs(i));
  }

  if (s != -1) {
    fill(All(used), 0);
    dfs(s, s);
    print(2);
    print(path.size());
    rep(i, 0, path.size()) {
      cout << path[i]+1;
      if (i < path.size()-1) cout << " ";
    }
    cout << endl;
  } else {
    fill(All(used), 0);
    color.resize(k);
    vi cnt(2);
    rep(i, 0, k) {
      if (!used[i]) c_dfs(i);
      cnt[color[i]]++;
    }
    int t;
    if (cnt[0] > cnt[1]) t = 0;
    else t = 1;
    int c = 0;
    vi ans;
    rep(i, 0, k) {
      if (color[i] == t) {
        ans.pb(i);
        c++;
      }
      if (c == half) break;
    }
    print(1);
    rep(i, 0, ans.size()) {
      cout << ans[i]+1;
      if (i < ans.size()-1) cout << " ";
    }
    cout << endl;
  }

  return 0;
};
