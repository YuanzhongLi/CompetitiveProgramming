#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
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

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;

int POWINT(int x, int n) {
  int ret = 1;
  rep(i, 0, n) ret *= x;
  return ret;
};

ll POWLL(int x, int n) {
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

const int INF = 1e9+7;

int solve(vector<int> A) {
  int n = (int)A.size();
  int ans = 0;
  rep(i, 1, n+1) {
    int target;
    rep(j, i, n+1) {
      if (A[j] <= i) {
        target = j;
        break;
      }
    }
    for (int j = target; j > i; j--) {
      swap(A[j], A[j-1]);
      ans++;
    }
  }

  return ans;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  int N;
  rep(t, 0, T) {
    cin >> N;
    vector<int> A(N+1);
    rep(i, 1, N+1) {
      int ai = 0;
      rep(j, 1, N+1) {
        char tmp;
        cin >> tmp;
        if (tmp == '1') {
          ai = j;
        }
      }
      A[i] = ai;
    }

    int ans = solve(A);
    printf("Case #%d: %d\n", t+1, ans);
  }

  return 0;
};
