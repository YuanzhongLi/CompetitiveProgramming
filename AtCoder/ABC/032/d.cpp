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

ll solve1(ll N, ll W, vl v, vl w) {
  ll half_N = N/2;
  vpl front, back; // <w, v>
  rep(i, 0, 1 << half_N) {
    ll tmp_v = 0, tmp_w = 0;
    rep(j, 0, half_N) {
      if ((i>>j)&1) {
        tmp_v += v[j];
        tmp_w += w[j];
      }
    }
    front.pb(make_pair(tmp_w, tmp_v));
  }

  rep(i, 0, 1 << (N-half_N)) {
    ll tmp_v = 0, tmp_w = 0;
    rep(j, 0, (N-half_N)) {
      if ((i>>j)&1) {
        tmp_v += v[j+half_N];
        tmp_w += w[j+half_N];
      }
    }
    back.pb(make_pair(tmp_w, tmp_v));
  }

  sort(All(front));
  sort(All(back));

  rep(i, 0, front.size()) {
    if (i > 0) {
      chmax(front[i].second, front[i-1].second);
    }
  }
  rep(i, 0, back.size()) {
    if (i > 0) {
      chmax(back[i].second, back[i-1].second);
    }
  }

  ll ans = 0;
  rep(i, 0, front.size()) {
    if (front[i].first > W) break;

    int ok = 0, ng = back.size();
    while (abs(ok-ng)>1) {
      int mid = (ok+ng)/2;
      if (back[mid].first+front[i].first <= W) {
        ok = mid;
      } else {
        ng = mid;
      }
    }
    chmax(ans, front[i].second+back[ok].second);
  }

  return ans;
};

ll solve2(ll N, ll W, vl v, vl w) {
  vvl dp(N+1, vl(min<ll>(200005, W+1)));
  ll ans = 0;
  rep(i, 1, N+1) {
    ll tmp_v = v[i-1], tmp_w = w[i-1];
    rep(j, 0, min<ll>(200005, W+1)) {
      chmax(dp[i][j], dp[i-1][j]);
      if (j-tmp_w >= 0) chmax(dp[i][j], dp[i-1][j-tmp_w]+tmp_v);
      chmax(ans, dp[i][j]);
    }
  }
  return ans;
};

ll solve3(ll N, ll W, vl v, vl w) {
  vvl dp(N+1, vl(200005, LINF));
  rep(i, 0, N+1) dp[i][0] = 0ll;

  ll ans = 0;
  rep(i, 1, N+1) {
    ll tmp_v = v[i-1], tmp_w = w[i-1];
    rep(j, 1, 200005) {
      chmin(dp[i][j], dp[i-1][j]);

      if (j-tmp_v >= 0) {
        chmin(dp[i][j], dp[i-1][j-tmp_v]+tmp_w);
      }
      if (dp[i][j] <= W) chmax(ans, (ll)j);
    }
  }
  return ans;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N, W; cin >> N >> W;
  vl v(N), w(N);
  ll w_max = 0;
  rep(i, 0, N) {
    cin >> v[i] >> w[i];
    chmax(w_max, w[i]);
  }

  if (N <= 30) {
    cout << solve1(N, W, v, w) << endl;
  } else if (w_max <= 1000) {
    cout << solve2(N, W, v, w) << endl;
  } else {
    cout << solve3(N, W, v, w) << endl;
  }


  return 0;
};
