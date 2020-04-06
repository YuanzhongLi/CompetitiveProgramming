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

class Act {
  public:
  int id, s, t;
  Act() {}
  Act(int id, int s, int t): id(id), s(s), t(t) {}
  bool operator < (const Act &a) const {
    if (s == a.s) {
      return t < a.t;
    } else {
      return s < a.s;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  rep(t, 0, T) {
    int N;
    cin >> N;
    vector<Act> acts(N);
    rep(i, 0, N) {
      int tmps, tmpt;
      cin >> tmps >> tmpt;
      acts[i] = Act(i, tmps, tmpt);
    }

    sort(All(acts));
    int j_time = 0, c_time = 0;
    bool flag = true;
    vector<char> ans(N);
    rep(i, 0, N) {
      auto act = acts[i];
      if (j_time <= act.s) {
        ans[act.id] = 'J';
        j_time = act.t;
      } else if (c_time <= act.s) {
        ans[act.id] = 'C';
        c_time = act.t;
      } else {
        flag = false;
        break;
      }
    }
    cout << "Case #" << t+1 << ": ";
    if (flag) {
      rep(i, 0, N) {
        cout << ans[i];
      }
      cout << endl;
    } else {
      cout << "IMPOSSIBLE" << endl;
    }
  }


  return 0;
};
