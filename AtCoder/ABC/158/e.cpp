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

int main() {
  int n, p;
  cin >> n >> p;
  string s;
  cin >> s;
  if (10 % p == 0) { // p == 2 || p == 5
    ll ans = 0;
    rep(r, 0, n)  { // r右端
      if ((s[r]- '0') % p == 0) {
        ans += r+1;
      }
    }
    cout << ans << endl;
    return 0;
  }

  vector<int> d(n+1);
  int ten = 1; // 10の何乗か
  for (int i = n - 1; i >= 0; --i) {
    int a = (s[i] - '0') * ten % p;
    d[i] = (d[i+1]+a) % p;
    ten *= 10; ten %= p;
  }

  vector<int> cnt(p);
  ll ans = 0;
  for (int i = n; i >= 0; --i) { //i = n: % p == 0を先にcntで一つカウントしてあげる
    ans += cnt[d[i]];
    cnt[d[i]]++;
  }

  cout << ans << endl;
  return 0;
};
