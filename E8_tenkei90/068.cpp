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

class Unionfind {
public:
  int N;
  vector<int> par; // parent
  vector<int> rank; // tree hight
  vector<int> size; // root node numbers
  int treeNum; // tree number
  Unionfind(int N) : N(N), par(N), rank(N, 0), size(N, 1) {
    for (int i = 0; i < N; i++) {
      par[i] = i;
    }
    treeNum = N;
  }
  // add node
  void addNode() {
    par.push_back(N);
    rank.push_back(0);
    size.push_back(1);
    N++;
    treeNum++;
  }
  int root(int x) {
    return par[x] == x ? x : par[x] = root(par[x]);
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
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
    } else {
      par[y] = x;
      size[x] += size[y];
      if (rank[x] == rank[y]) {
        rank[x] += 1;
      }
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

// 0-indexed
template<typename T>
class BIT {
public:
  int n;
  vector<T> dat;

  BIT(int n=0) {
    init(n);
  }

  void init(int nin) {
    n = nin;
    dat.resize(n);
    for (int i = 0; i < n; i++) dat[i] = 0;
  }

  // 0~iまでの和を求める
  T sum(int i) {
    T s = 0;
    while (i >= 0) {
      s += dat[i];
      i = (i & (i+1)) - 1;
    }
    return s;
  }

  // [i, j]の和を求める
  T sum_between(int i, int j){
    if(i > j) return 0;
    return sum(j) - sum(i-1);
  }

  // 一点更新
  void add(int i, T x) {
    while(i < n) {
      dat[i] += x;
      i |= i+1;
    }
  }

  // a[0]+...+a[ret] >= x
  int lower_bound(T x){
    int ret = -1;
    int k = 1;
    while (2*k <= n) k <<= 1;
    for( ;k>0; k>>=1){
      if(ret+k < n && dat[ret+k] < x){
        x -= dat[ret+k];
        ret += k;
      }
    }
    return ret + 1;
  }

  // debug
  void show() {
    for (int i = 0; i < n; i++) cout << sum_between(i,i) << " ";
    cout << endl;
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, Q; cin >> N >> Q;
  BIT<int> bit_o(N+2), bit_e(N+2);
  Unionfind uf(N+1);
  set<int> s;
  while (Q--) {
    int t, x, y, v; cin >> t >> x >> y >> v;
    if (t) {
      if (uf.same(x, y)) {
        int r = max(x, y), l = min(x, y);
        if (r == l) cout << v << endl;
        else {
          int s1, s2, diff;
          if ((r-l)&1) {
            if (l&1) {
              s1 = bit_o.sum_between(l, r);
              s2 = bit_e.sum_between(l+1, r-1);
            } else {
              s1 = bit_e.sum_between(l, r);
              s2 = bit_o.sum_between(l+1, r-1);
            }
            diff = s1-s2;
            cout << diff-v << endl;
          } else {
            if (l&1) {
              s1 = bit_o.sum_between(l, r-1);
              s2 = bit_e.sum_between(l+1, r);
            } else {
              s1 = bit_e.sum_between(l, r-1);
              s2 = bit_o.sum_between(l+1, r);
            }
            diff = s2-s1;
            cout << ((x == r) ? v-diff : v+diff) << endl;
          }
        }
      } else cout << "Ambiguous" << endl;
    } else {
      if (Find(s, x)) continue;

      s.insert(x);
      uf.unite(x, y);

      if (x&1) bit_o.add(x, v);
      else bit_e.add(x, v);
    }
  }

  return 0;
};
