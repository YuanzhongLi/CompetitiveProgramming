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

const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;

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

pair<vector<char>, vector<int>> Block(string s) {
  int num = 1;

  vector<char> v1;
  vector<int> v2;

  rep (i, 0, s.size()) {
    char c = s[i];
    if (i == 0) {
      v1.pb(c);
    } else if (c == s[i - 1]) {
      num++;
    } else {
      v2.pb(num);
      v1.pb(c);
      num = 1;
    }

    if (i == s.size() - 1) v2.pb(num);
  }

  return make_pair(v1, v2);
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n, m, x, y; cin >> n >> m >> x >> y;
    vector<vector<char>> grid(n, vector<char> (m));
    int white_cnt = 0;
    rep(i, 0, n) rep(j, 0, m) {
      cin >> grid[i][j];
      if (grid[i][j] == '.') white_cnt++;
    };
    if (2*x <= y) {
      cout << white_cnt * x << endl;
    } else {
      int ans = 0;
      rep(i, 0, n) {
        string tmp = "";
        rep(j, 0, m) tmp += grid[i][j];
        auto block = Block(tmp);
        auto chs = block.first;
        auto num = block.second;
        rep(k, 0, chs.size()) {
          if (chs[k] == '.') {
            ans += (num[k] / 2)*y;
            ans += (num[k] % 2)*x;
          }
        }
      }
      cout << ans << endl;
    }
  }

  return 0;
};
