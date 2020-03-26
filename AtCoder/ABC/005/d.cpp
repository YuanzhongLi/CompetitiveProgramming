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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int> (n));
  rep(i, 0, n) {
    rep(j, 0, n) {
      cin >> grid[i][j];
    }
  }

  int q;
  cin >> q;
  vector<int> P(q);
  rep(i, 0, q) {
    cin >> P[i];
  }

  vector<int> area(n*n+1, 0);

  // 縦横の累積和
  // i行目の長さjまでの累積和row_sum[i][j]
  vector<vector<int>> row_sum(n, vector<int> (n+1, 0));
  // i列目の長さjまでの累積和col_sum[i][j]
  vector<vector<int>> col_sum(n, vector<int> (n+1, 0));

  rep(i, 0, n) {
    rep(j, 0, n) {
      row_sum[i][j+1] = row_sum[i][j] + grid[i][j];
      col_sum[i][j+1] = col_sum[i][j] + grid[j][i];
    }
  }

  rep(r, 1, n+1) { // 横の長さ
    rep(c, 1, n+1) { // 縦の長さ
      int rc = r*c;

      int a = 0;
      rep(i, 0, r) {
        a += row_sum[i][c];
      }

      area[rc] = max(area[rc], a);

      int a1 = a;
      int a2 = a;

      rep(i, 0, n+1-r) {
        if (i > 0) {
          // 縦が一つ下がる時
          a2 += (row_sum[i+r-1][c]);
          a2 -= (row_sum[i-1][c]);
        }
        area[rc] = max(area[rc], a2);

        a1 = a2;

        rep(j, 1, n+1-c) { // 縦i, 横jが原点
          a1 += (col_sum[j+c-1][i+r] - col_sum[j+c-1][i]);
          a1 -= (col_sum[j-1][i+r] - col_sum[j-1][i]);
          area[rc] = max(area[rc], a1);
        }
      }
    }
  }

  int ma = 0;
  rep(i, 0, area.size()) {
    ma = max(ma, area[i]);
    area[i] = ma;
  }

  rep(i, 0, q) {
    int pi = P[i];
    cout << area[pi] << endl;
  }

  return 0;
};
