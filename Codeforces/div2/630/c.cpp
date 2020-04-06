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

void search(int i, int k, int n, vector<bool> &visited, map<char, int> &mp, string &s) {
  if (i < 0 || n <= i) return;
  if (visited[i]) return;
  visited[i] = true;
  if (Find(mp, s[i])) {
    mp[s[i]]++;
  } else {
    mp[s[i]] = 1;
  }
  search(i-k, k, n, visited, mp, s);
  search(i+k, k, n, visited, mp, s);
  search(n-1-i, k, n, visited, mp, s);
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  rep(T, 0, t) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<bool> visited(n, false);
    int ans = 0;
    rep(i, 0, n) {
      if (visited[i]) continue;
      map<char, int> mp;
      search(i, k, n, visited, mp, s);
      char ma_ch;
      int ma = 0;
      int total = 0;
      for (auto ele: mp) {
        total += ele.second;
        if (ele.second > ma) {
          ma = ele.second;
          ma_ch = ele.first;
        }
      }

      ans += (total - ma);
    }

    cout << ans << endl;
  }


  return 0;
};
