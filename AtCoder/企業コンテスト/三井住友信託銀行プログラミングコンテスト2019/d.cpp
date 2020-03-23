#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define BiSearchRangeNum(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y)turn idx;
#define deg_to_rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad_to_deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)

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
  int N;
  cin >> N;
  string S;
  cin >> S;

  vector<int> s(N);
  rep(i, 0, N) {
    s[i] = (int) S[i] - 48;
  }

  int ans = 0;

  rep(i, 0, 1000) {
    // 文字列にする
    string tmp = to_string(i);
    // 比べるint列
    vector<int> tmp2(3, 0);

    rep(j, 0, tmp.size()) {
      tmp2[2 - j] = tmp[tmp.size() - 1 - j] - 48;
    }

    // rep(j, 0, 3) {
    //   cout << tmp2[j];
    // }
    // cout << endl;

    int idx = 0;
    rep(j, 0, N) {
      int num = s[j];
      if (tmp2[idx] == num) {
        idx += 1;
        if (idx > 2) {
          ans += 1;
          break;
        }
      }
    }
  }

  cout << ans << endl;
};
