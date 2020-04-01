#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define llbidx(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y) // 二要素間の距離
#define deg2rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad2deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)
#define Find(set, element) set.find(element) != set.end()
#define Decimal(x) printf("%.10f\n", x) // 小数点を10桁まで表示
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;
#define debug(x) cerr << #x << ": " << (x) << "\n";

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
  rep(i, 0, n) ret *= x;
  return ret;
};

ll POWLL(ll x, int n) {
  ll ret = 1;
  rep(i, 0, n) ret *= x;
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

class SegmentTree{
  private:
  const int INIT = 0;
  static const int MAX_N = 1 << 17;
  int n;
  ll dat[2 * MAX_N -1];

  public:
  void init(ll n_){
    n = 1;
    while (n < n_) n*= 2;
    for (ll i=0; i< 2*n-1; i++) dat[i] = INIT;
  }

  // k番目の値(0-indexed)をaに変更
  void update(int k, ll a){
    k += n-1;
    dat[k] = a;
    while(k > 0){
      k = (k-1) / 2;
      dat[k] = max(dat[k*2 + 1], dat[k * 2 + 2]);
    }
  }

  //[a, b)のmaxを求める
  ll query(ll a, ll b, ll k = 0, ll l = 0, ll r = -1){
    if (r < 0) r = n;
    if (r <= a || b <= l) return INIT;

    if (a <= l && r <= b) return dat[k];

    ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return max(vl, vr);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  SegmentTree ST;
  ST.init(n);
  vl w(n);
  ll sum = 0;

  rep(i, 0, n) {
    ll w_; cin >> w_;
    w[i] = w_;
    sum += w[i];
  }

  rep(i, 0, n) {
    ll b;
    cin >> b;
    b--;

    ST.update(b, ST.query(0, b) + w[b]);
  }

  ll ans = (sum - ST.query(0, n)) * 2;
  cout << ans << endl;

  return 0;
};
