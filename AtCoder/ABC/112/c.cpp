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

struct Data {
  int x, y, h;
  bool operator < (const Data &d) const {
    return h < d.h;
  }
};

int main() {
  int N;
  cin >> N;

  vector<Data> data(N);

  int x, y, h;

  rep(i, 0, N) {
    cin >> x >> y >> h;
    data[i] = { x, y, h };
  }

  /* h == 0 が最後に見るようにするため */
  sort(All(data));
  reverse(All(data));

  int ans_cx, ans_cy, ans_h;

  rep(cx, 0, 101) {
    rep(cy, 0, 101) {
      int H = -1;
      bool flag = true;
      rep(i, 0, N) {
        Data d = data[i];
        x = d.x;
        y = d.y;
        h = d.h;

        int tmp = abs(x - cx) + abs(y - cy);
        int H2 = h + tmp;

        if (h == 0) {
          if (H <= tmp) {
            continue;
          } else {
            flag = false;
            break;
          }
        }

        if (H == -1) {
          H = H2;
        } else if (H != H2) {
          flag = false;
          break;
        }
      }

      if (flag) {
        ans_cx = cx;
        ans_cy = cy;
        ans_h = H;
        break;
      }
    }
  }

  cout << ans_cx << " " << ans_cy << " " << ans_h << endl;
};
