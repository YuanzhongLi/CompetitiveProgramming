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

PI f(string s) {
  int right = 0;
  int n = s.size();
  int left = 0;
  rep(i, 0, n) {
    if (s[i] == ')') {
      if (right == 0) {
        left++;
      } else {
        right--;
      }
    } else {
      right++;
    }
  }

  return make_pair(left, right);
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  vpi table(n);
  rep(i, 0, n) {
    string s; cin >> s;
    table[i] = f(s);
  }

  int cnt1 = 0, cnt2 = 0;
  vpi table2;
  int l_tot = 0, r_tot = 0;

  rep(i, 0, n) {
    int l = table[i].first;
    int r = table[i].second;
    if (l == 0 && r == 0) {
      continue;
    } else if (l == 0) {
      cnt1 += r;
    } else if (r == 0) {
      cnt2 += l;
    } else {
      l_tot += l;
      r_tot += r;
      table2.pb(table[i]);
    }
  }

  if (cnt1 + r_tot != cnt2 + l_tot) {
    cout << "No" << endl;
    return 0;
  }

  if (table2.empty()) {
    if (cnt1 == cnt2) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else if (table2.size() == 1) {
    if (l_tot == cnt1 && r_tot == cnt2) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else {
     set<int> ls, rs;
    rep (i, 0, table2.size()) {
      if (l_tot - r_tot + table2[i].second <= cnt1) ls.insert(i);
      if (r_tot - l_tot + table2[i].first <= cnt2) rs.insert(i);
    }

    if (ls.size() > 0 && rs.size() > 0) {
      if (ls.size() == 1 && rs.size() == 1) {
        for (int el: ls) {
          if (Find(rs, el)) {
            cout << "No" << endl;
          } else {
            cout << "Yes" << endl;
          }
        }
      } else {
        cout << "Yes" << endl;
      }
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
};
