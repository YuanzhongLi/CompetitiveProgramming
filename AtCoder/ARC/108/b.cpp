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

struct ID {
  int f, o, x;
};

bool check(ID id, vch &S) {
  int size = S.size();
  if (id.f < 0 || id.x >= size || id.f == INF) return false;
  if (S[id.f] == 'f' && S[id.o] == 'o' && S[id.x] == 'x') {
    return true;
  }
  return false;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N; cin >> N;
  vch s(N);
  rep(i, 0, N) cin >> s[i];

  queue<ID> q;
  rep(i, 0, N) {
    int fi = i, oi = i+1, ox = i+2;
    ID id = {fi, oi, ox};
    if (check(id, s)) {
      q.push(id);
    }
  }

  char out = '1';

  while (!q.empty()) {
    ID uid = q.front(); q.pop();
    if (!check(uid, s)) continue;
    s[uid.f] = out;
    s[uid.o] = out;
    s[uid.x] = out;

    int f = uid.f-1, b = uid.x+1;
    int f1 = INF, o1 = INF, x1 = INF;
    int f2 = INF, o2 = INF, x2 = INF;
    int cntf = 0, cntb = 0;

    for (int i = f; i >= 0; i--) {
      if (cntf == 2) break;
      if (s[i] != out) {
        if (cntf == 0) {
          f1 = o2 = i;
          cntf++;
        } else if (cntf == 1) {
          f2 = i;
          cntf++;
        }
      }
    }
    for (int i = b; i < N; i++) {
      if (cntb == 2) break;
      if (s[i] != out) {
        if (cntb == 0) {
          o1 = x2 = i;
          cntb++;
        } else if (cntb == 1) {
          x1 = i;
          cntb++;
        }
      }
    }
    q.push({f1, o1, x1});
    q.push({f2, o2, x2});
  }

  int ans = 0;
  rep(i, 0, N) {
    if (s[i] == out) continue;
    ans++;
  }
  cout << ans << endl;

  return 0;
};
