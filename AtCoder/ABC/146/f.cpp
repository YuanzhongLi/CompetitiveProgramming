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
  int N, M;
  cin >> N >> M;
  string S;
  cin >> S;
  reverse(All(S));
  int cur_idx = 0;
  int next_idx;
  vector<int> ans;
  bool flag = false;
  while (cur_idx < N) {
    next_idx = cur_idx + M;
    if (next_idx >= N) {
      ans.pb(N - cur_idx);
      flag = true;
      break;
    }

    bool flag2 = false;
    for (; next_idx > cur_idx; next_idx--) {
      if (S[next_idx] == '0') {
        flag2 = true;
        break;
      }
    }

    if (!flag2) {
      break;
    }
    ans.pb(next_idx - cur_idx);
    cur_idx = next_idx;
  }

  if (flag) {
    reverse(All(ans));
    rep(i, 0, ans.size() - 1) {
      cout << ans[i] << " ";
    }
    cout << ans[ans.size() - 1] << endl;
  } else {
    cout << -1 << endl;
  }
};
