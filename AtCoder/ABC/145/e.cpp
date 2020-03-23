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
  int N, T;
  cin >> N >> T;
  // <B美味しさ, A時間>
  vector<pair<int, int>> foods(N);
  rep(i, 0, N) {
    cin >> foods[i].second >> foods[i].first;
  }

  sort(All(foods));

  auto most_good_food = foods[foods.size() -  1];
  if (T == 1) {
    cout << most_good_food.first << endl;
    return 0;
  }

  vector<vector<int>> dp1(N + 1, vector<int> (T + 1, 0));
  rep(i, 1, N + 1) {
    auto food = foods[i - 1];
    rep(j, 1, T + 1) {
      int time = j;
      dp1[i][j] = dp1[i - 1][j];
      if (time >= food.second) {
        dp1[i][j] = max(dp1[i - 1][j - food.second] + food.first, dp1[i][j]);
      }
    }
  }

  reverse(All(foods));
  vector<vector<int>> dp2(N + 1, vector<int> (T + 1, 0));
  rep(i, 1, N + 1) {
    auto food = foods[i - 1];
    rep(j, 1, T + 1) {
      int time = j;
      dp2[i][j] = dp2[i - 1][j];
      if (time >= food.second) {
        dp2[i][j] = max(dp2[i - 1][j - food.second] + food.first, dp2[i][j]);
      }
    }
  }

  reverse(All(foods));

  int ans = 0;
  rep (i, 1, N+1) {
    rep(j, 0, T) {
      ans = max(ans, dp1[i-1][j] + dp2[N - i][T - 1 - j] + foods[i-1].first);
    }
  }
  cout << ans << endl;
};
