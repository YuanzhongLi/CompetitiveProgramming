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

int main() {
  int N, M;
  cin >> N >> M;

  int s, c;
  vector<int> sc(N, -1);

  bool flag = true;

  rep(i, 0, M) {
    cin >> s >> c;

    if (sc[s-1] == -1) { // 未指定
      sc[s-1] = c;
    } else {
      if (sc[s-1] != c) {
        flag = false;
        break;
      }
    }
  }

  if (!flag) {
    cout << -1 << endl;
    return 0;
  }

  if (N == 1) {
    if (M == 0) {
      cout << 0 << endl;
    } else {
      cout << sc[0] << endl;
    }
    return 0;
  }

  if (N == 2) {
    rep(ans, 10, 99) {
      int ten = ans / 10;
      int one = ans % 10;
      if ((ten == sc[0] || sc[0] == -1) && (one == sc[1] || sc[1] == -1)) {
        cout << ans << endl;
        return 0;
      }
    }

    cout << -1 << endl;
    return 0;
  }

  if (N == 3) {
    rep(ans, 100, 999) {
      int hun = ans / 100;
      int ten = (ans % 100) / 10;
      int one = (ans % 100) % 10;
      if ((hun == sc[0] || sc[0] == -1) && (ten == sc[1] || sc[1] == -1) && (one == sc[2] || sc[2] == -1)) {
        cout << ans << endl;
        return 0;
      }
    }

    cout << -1 << endl;
    return 0;
  }
};
