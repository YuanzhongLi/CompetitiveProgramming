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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n) {
    cin >> a[i];
    a[i]--;
  }

  vector<int> idx(n);
  rep(i, 0, n) {
    idx[a[i]] = i;
  }
  set<int> s;
  ll ans = 0;
  for (int x = n - 1; x >= 0; --x) {
    int i = idx[x];
    ll c = 0;
    { // calc c
      s.insert(i);
      vector<int> l(2, -1);
      vector<int> r(2, n);
      { // calc l
        auto it = s.find(i);
        rep(j, 0, 2) {
          if (it == s.begin()) break;
          --it;
          l[j] = *it;
        }
      }

      { // calc r
        auto it = s.find(i);
        rep(j, 0, 2) {
          ++it; // 先に++をする
          if (it == s.end()) break;
          r[j] = *it;
        }
      }

      vector<int> ls(2);
      ls[0] = i - l[0]; ls[1] = l[0] - l[1];

      vector<int> rs(2);
      rs[0] = r[0] - i; rs[1] = r[1] - r[0];
      c += (ll)ls[0]*rs[1] + (ll)ls[1]*rs[0];
    }

    ans += c*(x+1);
  }

  cout << ans << endl;
  return 0;
};
