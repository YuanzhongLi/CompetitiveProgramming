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

template<class I, class BiOp>
class SegTree {
  int n;
  std::vector<I> dat;
  BiOp op;
  I e;
public:
  SegTree(int n_, BiOp op, I e) : op(op), e(e) {
    n = 1;
    while (n < n_) { n *= 2; } // n is a power of 2
    dat.resize(2 * n);
    for (int i = 0; i < 2 * n - 1; i++) {
      dat[i] = e;
    }
  }
  /* ary[k] <- v */
  void update(int k, I v) {
    k += n - 1;
    dat[k] = v;
    while (k > 0) {
      k = (k - 1) / 2;
      dat[k] = op(dat[2 * k + 1], dat[2 * k + 2]);
    }
  }
  void update_array(const vector<I> vals, int k=0) {
    for (int i = 0; i < vals.size(); ++i) {
      update(k + i, vals[i]);
    }
  }
  // Updates all elements. O(n)
  void update_all(const I *vals, int len) {
    for (int k = 0; k < std::min(n, len); ++k) {
      dat[k + n - 1] = vals[k];
    }
    for (int k = std::min(n, len); k < n; ++k) {
      dat[k + n - 1] = e;
    }
    for (int b = n / 2; b >= 1; b /= 2) {
      for (int k = 0; k < b; ++k) {
	      dat[k + b - 1] = op(dat[k * 2 + b * 2 - 1], dat[k * 2 + b * 2]);
      }
    }
  }
  // l,r are for simplicity
  I querySub(int a, int b, int k, int l, int r) const {
    if (a >= b) return e; // 場合による
    if (r <= a || b <= l) return e;
    if (a <= l && r <= b) return dat[k];
    I vl = querySub(a, b, 2 * k + 1, l, (l + r) / 2);
    I vr = querySub(a, b, 2 * k + 2, (l + r) / 2, r);
    return op(vl, vr);
  }
  // [a, b)
  I query(int a, int b) const {
    return querySub(a, b, 0, 0, n);
  }
};

// struct ADD {
//   int operator() (int a, int b) const {
//     return a + b;
//   }
// };

// struct MAX {
//   int operator() (int a, int b) const {
//     return max(a, b);
//   }
// };

struct MIN {
  int operator() (int a, int b) const {
    return min(a, b);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, Q; cin >> N >> Q;
  SegTree<int, MIN> st(n_max+1, MIN(), INF);

  vector<set<PI>> table(n_max);
  map<int, int> rate_mp;
  map<int, int> pos_mp;
  rep(i, 0, N) {
    int a, b;
    cin >> a >> b;
    b--;
    rate_mp[i] = a; // rate
    pos_mp[i] = b; // pos
    table[b].insert(make_pair(-a, i));
    int rate = st.query(b, b+1);
    if (rate == INF || a > rate) {
      st.update(b, a);
    }
  }

  rep(i, 0, Q) {
    int c, d; cin >> c >> d;
    c--; d--;
    int c_rate = rate_mp[c]; // 子供のrate
    int c_pos = pos_mp[c]; // 子供のいる幼稚園

    int max_d_rate = st.query(d, d+1);
    if (max_d_rate == INF || c_rate > max_d_rate) {
      st.update(d, c_rate);
    }

    table[d].insert(make_pair(-c_rate, c));
    table[c_pos].erase(make_pair(-c_rate, c));
    pos_mp[c] = d;

    if (table[c_pos].size() == 0) {
      st.update(c_pos, INF);
    } else {
      auto it = table[c_pos].begin();
      auto c_pos_max = *it;
      int c_pos_max_rate = -c_pos_max.first;
      st.update(c_pos, c_pos_max_rate);
    }

    cout << st.query(0, n_max+1) << endl;
  }



  return 0;
};
