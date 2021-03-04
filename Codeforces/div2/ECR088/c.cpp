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

const ld esp = 1e-10;

ld f(ld n, ld h, ld c) {
  return (h+(n-1.0)*(c+h))/(2*n-1.0);
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T; cin >> T;
  while (T--) {
    ld h, c, t;
    cin >> h >> c >> t;
    if (t-(h+c)/2.0 < esp) {
      cout << 2 << endl;
    } else {
      ll ok = 1;
      ll ng = 1000100010001ll;
      int cnt = 0;
      while (abs(ok-ng)>1ll) {
        if (cnt > 5000) break;
        ll mid = (ok+ng)/2ll;
        ld dmid = (ld)mid;
        if (f(dmid, h, c)+esp > t) {
          ok = mid;
        } else {
          ng = mid;
        }
        cnt++;
      }

      ld t1 = f((ld)ok, h, c);
      ld t2 = f((ld)(ok+1.0), h, c);
      ld t3 = (h+c)/2.0;
      ld diff1 = abs(t1-t);
      ld diff2 = abs(t2-t);
      ld diff3 = abs(t3-t);
      if (diff1 <= diff2) {
        if (diff3 <= diff1) {
          cout << 2 << endl;
        } else {
          cout << 2*ok-1 << endl;
        }
      } else {
        if (diff3 <= diff2) {
          cout << 2 << endl;
        } else {
          cout << 2*(ok+1)-1 << endl;
        }
      }
    }
  }

  return 0;
};
