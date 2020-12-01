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

class Unionfind {
public:
  int N;
  vector<int> par; // parent
  vector<int> rank; // 木の高さ
  vector<int> size; // 節点が属する木の節点数
  vector<map<int, int>> vec_mp;
  int treeNum; // 木の数
  Unionfind(int N) : N(N), par(N), rank(N, 0), size(N, 1), vec_mp(N) {
    for (int i = 0; i < N; i++) {
      par[i] = i;
    }
    treeNum = N;
  }

  void update_vec_mp(int i, int c) {
    vec_mp[i][c] = 1;
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
      for (auto pi: vec_mp[x]) {
        if (Find(vec_mp[y], pi.first)) {
          vec_mp[y][pi.first] += pi.second;
        } else {
          vec_mp[y][pi.first] = pi.second;
        }
      }
      vec_mp[x].clear();
    } else {
      par[y] = x;
      size[x] += size[y];
      if (rank[x] == rank[y]) {
        rank[x] += 1;
      }
      for (auto pi: vec_mp[y]) {
        if (Find(vec_mp[x], pi.first)) {
          vec_mp[x][pi.first] += pi.second;
        } else {
          vec_mp[x][pi.first] = pi.second;
        }
      }
      vec_mp[y].clear();
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, Q; cin >> N >> Q;
  Unionfind uf(N);

  rep(i, 0, N) {
    int c; cin >> c;
    uf.update_vec_mp(i, c);
  }

  rep(i, 0, Q) {
    int com; cin >> com;
    if (com == 1) {
      int a, b; cin >> a >> b;
      a--; b--;
      uf.unite(a, b);
    } else {
      int x, y; cin >> x >> y;
      x--;
      int r = uf.root(x);
      if (Find(uf.vec_mp[r], y)) {
        cout << uf.vec_mp[r][y] << endl;
      } else {
        cout << 0 << endl;
      }
    }
  }
  return 0;
};
