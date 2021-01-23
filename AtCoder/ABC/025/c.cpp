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

int func(int id, int i, int j) {
  int digit = i*3+j;
  rep(k, 0, digit) {
    id /= 3;
  }
  return id % 3;
};

int func2(int digit_num, int i, int j) {
  int digit = i*3+j;
  return digit_num * POW(3, digit);
};

vvi B(2, vi(3));
vvi C(3, vi(2));

PI calc_point(int id) {
  vvi game(3, vi(3));
  int t = 0, n = 0;
  rep(i, 0, 3) {
    rep(j, 0, 3) {
      game[i][j] = func(id, i, j);
    }
  }
  rep(i, 0, 3) {
    rep(j, 0, 3) {
      if (i < 2) {
        if (game[i][j] == game[i+1][j]) t += B[i][j];
        else n += B[i][j];
      }
      if (j < 2) {
        if (game[i][j] == game[i][j+1]) t += C[i][j];
        else n += C[i][j];
      }
    }
  }
  return make_pair(t, n);
};

vpi dp(POW(3, 9),  make_pair(-INF, -INF));
PI dfs(int depth, int id) {
  if (dp[id].first != -INF) return dp[id];
  if (depth == 9) {
    dp[id] = calc_point(id);
    return dp[id];
  }

  if (!(depth&1)) { // taka's turn
    rep(i, 0, 3) {
      rep(j, 0, 3) {
        int digit_num = func(id, i, j);
        if (digit_num == 0) {
          int next_id = id + func2(1, i, j);
          auto next_pi = dfs(depth+1, next_id);
          if (next_pi.first > dp[id].first) {
            dp[id] = next_pi;
          }
        }
      }
    }
  } else { // nao's trun
    rep(i, 0, 3) {
      rep(j, 0, 3) {
        int digit_num = func(id, i, j);
        if (digit_num == 0) {
          int next_id = id + func2(2, i, j);
          auto next_pi = dfs(depth+1, next_id);
          if (next_pi.second > dp[id].second) {
            dp[id] = next_pi;
          }
        }
      }
    }
  }

  return dp[id];
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  rep(i, 0, 2) rep(j, 0, 3) cin >> B[i][j];
  rep(i, 0, 3) rep(j, 0, 2) cin >> C[i][j];
  auto pi = dfs(0, 0);
  cout << pi.first << endl;
  cout << pi.second << endl;

  return 0;
};
