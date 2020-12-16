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

bool check(vector<deque<int>> &vd) {
  rep(i, 0, vd.size()) {
    if (!vd[i].empty()) return true;
  }
  return false;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, k; cin >> n >> m >> k;
  vector<deque<int>> vd(4);
  rep(i, 0, n) {
    int t, a, b; cin >> t >> a >> b;
    int j = a+b*2;
    vd[j].pb(t);
  }

  rep(i, 0, 4) sort(All(vd[i]));

  vector<priority_queue<int>> vpq(4);
  int tmp = m;
  int a_cnt = 0, b_cnt = 0;
  ll T = 0;
  while (tmp) {
    vi v(4, INF);
    rep(i, 0, 4) {
      if (!vd[i].empty()) v[i] = vd[i].front();
    }
    vi ord(4);
    iota(All(ord), 0);
    sort(All(ord), [&](int a, int b) {
      return v[a] < v[b];
    });

    sort(All(v));

    int id = ord[0];
    int a = id&1, b = (id>>1)&1;
    a_cnt += a; b_cnt += b;
    T += v[0];
    vd[id].pop_front();
    vpq[id].push(v[0]);
    tmp--;
  }

  int ai = 1, bi=2, abi=3, nei=0;

  int re = n-m;
  while (re) {
    vi v(4, INF);
    rep(i, 0, 4) {
      if (!vd[i].empty()) v[i] = vd[i].back();
    }
    ll a = v[ai], b = v[bi], ab=v[abi], ne= v[nei];

    vi v_(4, -INF);
    rep(i, 0, 4) {
      if (!vpq[i].empty()) v_[i] = vpq[i].top();
    }
    ll a_=v_[ai], b_=v_[bi], ab_=v_[abi], ne_=v_[nei];

    int di = -1, pqi = -1;
    if (a_cnt >= k && b_cnt >= k) {
      break;
    } else if (a_cnt >= k) {
      if (ab <= b) { // ab
        di = abi;
        if (a_ <= ne_) pqi = nei;
        else pqi = ai;
      } else { // b
        di = bi;
        if (a_cnt > k) {
          if (a_ <= ne_) pqi = nei;
          else pqi = ai;
        } else { // a == a_cnt
          pqi = nei;
        }
      }
    } else if (b_cnt >= k) {
      if (ab <= a) { // ab
        di = abi;
        if (b_ <= ne_) pqi = nei;
        else pqi = bi;
      } else { // a
        di = ai;
        if (b_cnt > k) {
          if (b_ <= ne_) pqi = nei;
          else pqi = bi;
        } else { // b == b_cnt
          pqi = nei;
        }
      }
    } else  {
      pqi = nei;
      if (a <= b) {

      } else {

      }

      if (ab <= a && ab <= b) {
        if (ne_ >= a_ && ne_ >= b_) pqi = ne;
        else if (a_ >= b_) pqi = ai;
        else pqi = bi;
      }
    }

    re--;
  };

  if (a_cnt >= k && b_cnt >= k) {
    cout << T << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
};
