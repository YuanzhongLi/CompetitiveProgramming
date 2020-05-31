#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (ll)s; i < (ll)n; i++)
#define rrep(i,n,e) for (int i = (ll)n-1; i >= (ll)e; i--)
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define llbidx(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y) // 二要素間の距離
// #define M_PI 3.14159265358979323846 // CFでは定義しておく必要あり
#define deg2rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad2deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)
#define Find(set, element) set.find(element) != set.end()
#define Decimal(x) cout << fixed << setprecision(10) << x << endl; // 小数点を10桁まで表示
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << "\n";
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define endl "\n"
// gcj print用
#define Case(x) printf("Case #%d: ", x);

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<int>>> vvvl;
typedef vector<PI> vpi;
typedef vector<vector<PI>> vvpi;
typedef vector<vector<vector<PI>>> vvvpi;
typedef vector<PLL> vpl;
typedef vector<vector<PLL>> vvpl;
typedef vector<vector<vector<PLL>>> vvvpl;

int POWINT(int x, int n) {
  int ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
};

ll POWLL(ll x, int n) {
  ll ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
};

template<class T>
inline bool chmax(T &a, T b) {
  if(a < b) {
    a = b;
    return true;
  }
  return false;
};

template<class T>
inline bool chmin(T &a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
};

void print() {
  cout << endl;
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
void print(vector<T> &vec, ll k){
   ll n = vec.size();
   k = min(k, n);
   rep(i, 0, k-1) cout << vec[i] << " ";
   cout << vec[k-1] << endl;
};

template <class T>
void print(vector<vector<T>> &df) {
  for (auto& vec : df) {
    print(vec);
  }
};

template<class T, class U>
void print(pair<T,U> &p){
  cout << p.first << " " << p.second << "\n";
};

const ll LINF = LONG_MAX;

ll A, B, C, D;
map<ll, ll> mp;

void init() {
  mp.clear();
  mp[0] = 0;
  mp[1] = D;

  mp[2] = 2*D;
  chmin(mp[2], D+A);

  mp[3] = 3*D;
  chmin(mp[3], D+A+D);
  chmin(mp[3], D+B);

  mp[4] = 4*D;
  chmin(mp[4], A+mp[2]);
  chmin(mp[4], 2*A+D);
  chmin(mp[4], D+mp[3]);
  chmin(mp[4], D+C+D);
};

ll dfs(ll N) {
  if (Find(mp, N)) return mp[N];
  ll res = LINF;
  if (LINF/D > N) res = N * D;

  {
    ll n = (N/5);
    ll nn = ((N+4)/5);
    chmin(res, C+abs(N-n*5)*D+dfs(n));
    chmin(res, C+abs(N-nn*5)*D+dfs(nn));
  }

  {
    ll n = (N/3);
    ll nn = ((N+2)/3);
    chmin(res, B+abs(N-n*3)*D+dfs(n));
    chmin(res, B+abs(N-nn*3)*D+dfs(nn));
  }

  {
    ll n = (N/2);
    ll nn = ((N+1)/2);
    chmin(res, A+abs(N-n*2)*D+dfs(n));
    chmin(res, A+abs(N-nn*2)*D+dfs(nn));
  }

  return mp[N] = res;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T; cin >> T;
  while (T--) {
    ll N;
    cin >> N >> A >> B >> C >> D;
    init();
    cout << dfs(N) << endl;
  }

  return 0;
};
