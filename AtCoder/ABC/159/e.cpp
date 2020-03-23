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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int H, W, K;
  cin >> H >> W >> K;

  vector<vector<int>> grid(H, vector<int> (W));
  char ch;
  rep(i, 0, H) {
    rep(j, 0, W) {
      cin >> ch;
      grid[i][j] = (int) ch - '0';
    }
  }

  int ans = INF;

  rep(i, 0, (1 << (H-1))) {
    vector<int> tmp;
    tmp.pb(0);
    for (int j = 0; j < H-1; j++) {
      if ((i & (1 << j)) == (1 << j)) {
        tmp.pb(j+1);
      }
    }
    tmp.pb(H);

    map<PI, int> mp; // ホワイトチョコカウント
    vector<PI> v;
    rep(j, 0, tmp.size()-1) {
      mp[make_pair(tmp[j], tmp[j+1])] = 0;
      v.pb(make_pair(tmp[j], tmp[j+1]));
    }

    int tmp_ans = tmp.size() - 2;

    bool possible = true;

    rep(j, 0, W) {
      bool flag = false;
      for (auto pi: v) {
        int w_cnt = 0;
        rep(k, pi.first, pi.second) {
          w_cnt += grid[k][j];
        }
        if (w_cnt > K) {
          possible = false;
        } else if (mp[pi] + w_cnt > K) {
          flag = true;
        }
      }

      if (flag) {
        tmp_ans++;
        for (auto pi: v) {
          int w_cnt = 0;
          rep(k, pi.first, pi.second) {
            w_cnt += grid[k][j];
          }
          mp[pi] = w_cnt;
        }
      } else {
        for (auto pi: v) {
          int w_cnt = 0;
          rep(k, pi.first, pi.second) {
            w_cnt += grid[k][j];
          }
          mp[pi] += w_cnt;
        }
      }
    }

    if (!possible) {
      continue;
    } else {
      ans = min(ans, tmp_ans);
    }
  }

  cout << ans << endl;

  return 0;
};
