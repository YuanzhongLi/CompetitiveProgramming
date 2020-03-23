#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define BiSearchRangeNum(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y)

int main() {
  int H, W, A, B;
  cin >> H >> W >> A >> B;
  if ((A == 0) && (B == 0)) {
    rep(i, 0, H) {
      rep(j, 0, W) {
        cout << 1;
      }
      cout << endl;
    }
    return 0;
  } else if (B == 0) {
    rep(i, 0, H) {
      rep(j, 0, W) {
        if (j < A) {
          cout << 1;
        } else {
          cout << 0;
        }
      }
      cout << endl;
    }

    return 0;
  } else if (A == 0) {
    rep(i, 0, H) {
      rep(j, 0, W) {
        if (i < B) {
          cout << 1;
        } else {
          cout << 0;
        }
      }
      cout << endl;
    }

    return 0;
  } else {
    rep(i, 0, H) {
      rep(j, 0, W) {
        if (i < B && j < A) {
          cout << 1;
        } else if (i >= B && j >= A) {
          cout << 1;
        } else {
          cout << 0;
        }
      }
      cout << endl;
    }
    return 0;
  }
};
