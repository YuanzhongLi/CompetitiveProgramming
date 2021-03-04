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
}

template <class T>
void print(vector<T> &vec) {
  for (auto& a : vec) {
    cout << a;
    if (&a != &vec.back()) cout << " ";
  }
  cout << endl;
}

template <class T>
void print(vector<T> &vec, ll k){
   ll n = vec.size();
   k = min(k, n);
   rep(i, 0, k-1) cout << vec[i] << " ";
   cout << vec[k-1] << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
  for (auto& vec : df) {
    print(vec);
  }
}

template<class T, class U>
void print(pair<T,U> &p){
  cout << p.first << " " << p.second << "\n";
}

const int INF = 1e9+7;

int solve(string s) {
  int n = s.size();
  bool has1, has2, has3;
  has1 = has2 = has3 = false;
  vi idx1, idx2, idx3;
  idx1.pb(-INF); idx2.pb(-INF); idx3.pb(-INF);
  rep(i, 0, n) {
    if (s[i] == '1') {
      has1 = true;
      idx1.pb(i);
    } else if (s[i] == '2') {
      has2 = true;
      idx2.pb(i);
    } else {
      has3 = true;
      idx3.pb(i);
    }
  }
  idx1.pb(INF), idx2.pb(INF), idx3.pb(INF);

  if (has1 && has2 && has3) {
    int ret = n;
    for (int i1: idx1) {
      if (i1 == -INF || i1 == INF) continue;
      int r2 = lbidx(idx2, i1);
      int r3 = lbidx(idx3, i1);
      int l2 = r2-1;
      int l3 = r3-1;
      int rr2 = idx2[r2], rr3 = idx3[r3], ll2 = idx2[l2], ll3 = idx3[l3];
      int ll_mi = min(ll2, ll3);
      int rr_ma = max(rr2, rr3);
      chmin(ret, (i1-ll_mi)+1);
      chmin(ret, (rr_ma-i1)+1);
      chmin(ret, (rr2-ll3)+1);
      chmin(ret, (rr3-ll2)+1);
    }

    return ret;
  } else {
    return 0;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int ans = solve(s);
    cout << ans << endl;
  }

  return 0;
};
