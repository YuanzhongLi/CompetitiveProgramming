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
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  vector<int> monster(n);
  int hp;
  int rem;
  rep(i, 0, n) {
    scanf("%d", &hp);
    rem = hp % (a + b);
    if (rem == 0) {
      monster[i] = (a + b);
    } else {
      monster[i] = rem;
    }
  }

  sort(All(monster));

  int point = 0;
  rep(i, 0, n) {
    hp = monster[i];
    if (hp <= a) {
      point += 1;
    } else {
      int need_k = (hp + a - 1) / a - 1;
      if (k >= need_k) {
        k -= need_k;
        point += 1;
      }
    }
  }

  cout << point << endl;
};
