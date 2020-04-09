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
# define endl "\n"

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n  >> k;
  vector<char> s(n);
  rep(i, 0, n) {
    cin >> s[i];
  }
  // c最大, cc最小
  int c = 0, cc = 0;
  vvi ans;
  rep(i, 0, n) {
    vi axi;
    int hmm = c;
    rep(j, 0, n-1) {
      if (s[j] == 'R' and s[j+1] == 'L') {
        swap(s[j], s[j+1]);
        j++;
        c++;
        axi.pb(j);
      }
    }

    if (hmm != c) { // swapが起きた
      cc++;
    }
    if (axi.size() > 0) ans.pb(axi);
  }

  if (cc <= k && k <= c) {
    int i = 0;
    while (k) {
      if (ans[i].size() + cc - 1 - i >= k) {
        rep(j, 0, k - (cc - i)) {
          cout << 1 << " " << ans[i][j] << endl;
        }

        if (k - (cc - i) < ans[i].size()) {
          cout << ans[i].size() - (k - (cc -i)) << " ";
          rep(j, k - (cc - i), ans[i].size()) {
            cout << ans[i][j];
            if (j < ans[i].size() - 1) cout << " ";
          }
          cout << endl;
        }

        rep(j, i+1, cc) {
          cout << ans[j].size() << " ";
          rep(l, 0, ans[j].size()) {
            cout << ans[j][l];
            if (l < ans[j].size() - 1) {
              cout << " ";
            }
          }
          cout << endl;
        }
        k = 0;
      } else {
        rep(j, 0, ans[i].size()) {
          cout << 1 << " " << ans[i][j] << endl;
        }
        k -= ans[i].size();
        i++;
      }
    }
  } else {
    cout << -1 << endl;
  }

  return 0;
};
