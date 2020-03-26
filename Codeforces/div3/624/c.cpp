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

vector<int> solve(string s, vector<int> miss) {
  vector<int> ret(26, 0);

  vector<vector<int>> memo(s.size()+1, vector<int> (26, 0));

  rep(i, 1, s.size()+1) {
    char ch = s[i-1];
    memo[i] = memo[i-1];
    memo[i][(int) ch - 'a'] += 1;
  }

  for (auto m: miss) {
    rep(i, 0, 26) {
      ret[i] += memo[m][i];
    }
  }

  rep(i, 0, 26) {
    ret[i] += memo[s.size()][i];
  }

  return ret;
};

int main() {
  int t;
  cin >> t;

  vector<vector<int>> ans(t, vector<int> (26, 0));

  int n, m;
  rep(i, 0, t) {
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> miss(m);
    rep(j, 0, m) {
      cin >> miss[j];
    }

    ans[i] = solve(s, miss);
  }

  rep(i, 0, t) {
    rep(j, 0, 26) {
      if (j < 25) {
        printf("%d ", ans[i][j]);
      } else {
        printf("%d\n", ans[i][j]);
      }
    }
  }

  return 0;
};
