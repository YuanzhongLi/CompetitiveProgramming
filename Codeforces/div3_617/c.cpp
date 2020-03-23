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

static const int INF = 1e9+7;

PI solve(string s) {
  int size = s.size();
  map<PI, int> M;
  M.emplace(PI(0, 0), 0);

  PI position = { 0, 0 };
  int minimum_dis = INF;
  PI ret = { -1, -1};
  rep(i, 0, size) {
    int idx = i+1;
    char ch = s[i];
    if (ch == 'L') {
      position.first -= 1;
    } else if (ch == 'R') {
      position.first += 1;
    } else if (ch == 'U') {
      position.second += 1;
    } else if (ch == 'D') {
      position.second -= 1;
    }

    if (Find(M, position)) {
      int l = M[position] + 1;
      int r = idx;

      if (r - l + 1 < minimum_dis) {
        ret.first = l;
        ret.second = r;
        minimum_dis = r - l + 1;
      }

      M[position] = idx;
    } else {
      M.emplace(position, idx);
    }
  }

  return ret;
};

int main() {
  int t;
  cin >> t;
  vector<PI> ans(t);

  int n;
  rep(i, 0, t) {
    cin >> n;
    string s;
    cin >> s;
    ans[i] = solve(s);
  }

  rep(i, 0, t) {
    if (ans[i].first == -1) {
      printf("-1\n");
    } else {
      printf("%d %d\n", ans[i].first, ans[i].second);
    }
  }

  return 0;
};
