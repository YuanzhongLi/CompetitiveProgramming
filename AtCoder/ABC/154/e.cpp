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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string N;
  cin >> N;

  int digit = N.size();

  int top = N[0] - '0';

  int K; cin >> K;

  // [i][j]間が全部0かどうか
  vector<vector<bool>> memo(digit, vector<bool> (digit, false));
  rep(i, 0, digit) {
    rep(j, i+1, digit) {
      bool flag = true;
      rep(k, i+1, j) {
        if (N[k] != '0') {
          flag = false;
          break;
        }
      }
      if (flag) memo[i][j] = true;
    }
  }

  if (K == 1) {
    int ans = 9*(digit - 1);
    ans += top;
    cout << ans << endl;

  } else if (K == 2) {
    int ans = 9*9 * ((digit-1) * (digit-2) / 2);

    ans += (top-1) * 9 * (digit-1);

    rep(i, 1, digit) {
      int num = (int)N[i] - '0';
      if (memo[0][i]) {
        if (num == 0) continue;
        ans += num;
      } else {
        ans += 9;
      }
    }
    cout << ans << endl;

  } else if (K == 3) {

    int ans = 9*9*9*((digit-1)*(digit-2)*(digit-3)/6);
    ans += (top-1)*9*9*((digit-1)*(digit-2)/2);

    rep(i, 1, digit) {
      rep(j, i+1, digit) {
        if (memo[0][i]) {
          int num_i = (int)N[i] - '0';
          if (num_i == 0) continue;
          ans += (num_i-1) * 9;

          if (memo[i][j]) {
            int num_j = (int)N[j] - '0';
            if (num_j == 0) continue;
            ans += num_j;
          } else {
            ans += 9;
          }
        } else {
          ans += 9*9;
        }
      }
    }

    cout << ans << endl;
  }

  return 0;
};
