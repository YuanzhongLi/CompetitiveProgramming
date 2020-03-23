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

// 0~50lvそれぞれのバーガーが全部で何枚か
vector<ll> layer_nums(51);

void init_layer_nums(void) {
  layer_nums[0] = (ll) 1;
  rep(i, 1, 51) {
    layer_nums[i] = (2 * layer_nums[i - 1] + (ll)3);
  }
};

// 0~50lvそれぞれのバーガーのpatteyが全部で何枚か
vector<ll> patty_nums(51);

void init_patty_nums(void) {
  patty_nums[0] = (ll) 1;
  rep(i, 1, 51) {
    patty_nums[i] = (2 * patty_nums[i - 1] + (ll) 1);
  }
};

ll solve(int N, ll X) {
  if (N == 0) {
    if (X <= 0) {
      return 0;
    } else {
      return 1;
    }
  } else if (X <= 1 + layer_nums[N - 1]) {
    return solve(N - 1, X - 1);
  } else {
    return patty_nums[N - 1] + 1 + solve(N - 1, X - 2 - layer_nums[N - 1]);
  }
};

int main() {
  int N;
  cin >> N;
  ll X;
  cin >> X;

  init_layer_nums();
  init_patty_nums();

  ll ans = solve(N, X);

  cout << ans << endl;
};
