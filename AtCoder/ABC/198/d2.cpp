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

set<int> s;
bool check(vi &A1, vi &A2, vi &A3) {
  for (int a: A1) s.insert(a);
  for (int a: A2) s.insert(a);
  for (int a: A3) s.insert(a);
  if (s.size() > 10) return false;
  if (A3.size() < A1.size() || A3.size() < A2.size()) return false;
  return true;
};

vi mp(26, -1);
int get_num(vi &A) {
  int d = 1;
  int ret = 0;
  for (char a: A) {
    ret += d * mp[a];
    d *= 10;
  }
  return ret;
};

vi s2a(string &s) {
  int N = s.size();
  vi A(N);
  rep(i,0,N) A[i] = (int)s[i]-'a';
  reverse(All(A));
  return A;
};


signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s1, s2, s3; cin >> s1 >> s2 >> s3;
  vi A1 = s2a(s1), A2 = s2a(s2), A3 = s2a(s3);
  if (!check(A1, A2, A3)) {
    cout << "UNSOLVABLE" << endl; return 0;
  }

  vi nums; for (int num: s) nums.pb(num);
  int N = nums.size();
  vi V(10); rep(i,0,10) V[i] = i;
  int x1 = -1, x2 = -1, x3 = -1;
  do {
    rep(i,0,N) mp[nums[i]] = V[i];
    if (mp[A1.back()] == 0 || mp[A2.back()] == 0 || mp[A3.back()] == 0) continue;
    int x = get_num(A1), y = get_num(A2), z = get_num(A3);
    if (x+y==z) { x1 = x; x2 = y; x3 = z; break; }
  } while (next_permutation(All(V)));

  if (x1 == -1) {
    cout << "UNSOLVABLE" << endl;
  } else {
    cout << x1 << endl;
    cout << x2 << endl;
    cout << x3 << endl;
  }

  return 0;

};
