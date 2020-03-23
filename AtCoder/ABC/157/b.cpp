#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define llbidx(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y) // 二要素間の距離
#define deg2rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad2deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)
#define Find(set, element) set.find(element) != set.end()

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;

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

bool solve(vector<vector<bool>> mark) {
  bool ret = false;

  rep(row, 0, 3) {
    bool flag = true;
    rep(col, 0, 3) {
      if (!mark[row][col]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      return true;
    }
  }

  rep(col, 0, 3) {
    bool flag = true;
    rep(row, 0, 3) {
      if (!mark[row][col]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      return true;
    }
  }

  if (mark[0][0] && mark[1][1] && mark[2][2]) {
    return true;
  }

  if (mark[0][2] && mark[1][1] && mark[2][0]) {
    return true;
  }

  return ret;
};

int main() {
  int A[3][3];

  vector<vector<bool>> mark(3, vector<bool> (3, false));

  rep(i, 0, 9) {
    int row = i / 3;
    int col = i % 3;
    cin >> A[row][col];
  }

  int N;
  cin >> N;

  int b;
  rep(i, 0, N) {
    cin >> b;
    rep(i, 0, 9) {
      int row = i / 3;
      int col = i % 3;
      if (A[row][col] == b) {
        mark[row][col] = true;
      }
    }
  }

  if (solve(mark)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
};
