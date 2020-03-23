#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define BiSearchRangeNum(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y) return idx;
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
  string s;
  string t;
  cin >> s >> t;
  int s_len = s.size();
  int t_len = t.size();

  int max_len = max(s_len, t_len);

  string s2 = s+s;
  vector<vector<int>> dic_s(26);

  rep(i, 0, s_len*2) {
    char ch = s2[i];
    dic_s[ch - 97].pb(i);
  }

  // rep(i, 0, 26) {
  //   if (dic_s[i].empty()) {
  //     continue;
  //   }
  //   cout << (char)i+97 << endl;
  //   rep(j, 0, dic_s[i].size()) {
  //     cout << dic_s[i][j] << endl;
  //   }
  // }

  vector<vector<int>> next(s_len, vector<int> (26, 0));

  rep(i, 0, s_len) {
    char ch = s[i];
    rep(alphabet, 0, 26) {
      int idx = lbidx(dic_s[alphabet], i+1);
      if (idx == dic_s[alphabet].size()) {
        continue;
      }

      int dis = dic_s[alphabet][idx] - i;
      next[i][alphabet] = dis;
    }
  }

  bool is = true;

  ll ans = 0;

  char start_ch_t = t[0];
  int start_idx = -1;
  rep(i, 0, s_len) {
    char ch_si = s[i];
    if (start_ch_t == ch_si) {
      start_idx = i;
      break;
    }
  }

  if (start_idx < 0) {
    cout << -1 << endl;
    return 0;
  }

  int idx = start_idx;
  ans += (start_idx + 1);
  rep(i, 0, t_len-1) {
    char cur_ch = t[i];
    char next_ch = t[i+1];
    int dis = next[idx][(int)next_ch - 97];
    if (dis == 0) {
      is = false;
    }
    ans += dis;
    idx = (idx + dis) % s_len;
  }

  if (is) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
};
