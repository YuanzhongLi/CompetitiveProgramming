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
  int N, K;
  cin >> N >> K;
  vector<char> S(N);
  vector<char> S1(N+2);
  vector<char> S2(N+2);
  S1[0] = S1[N+1] = 'L';
  S2[0] = S2[N+1] = 'R';

  rep(i, 0, N) {
    cin >> S[i];
    S1[i+1] = S[i];
    S2[i+1] = S[i];
  }

  int ans = 0;
  int cnt = 0;


  // Rによるポイント
  rep(i, 0, N+2) {
    if (S1[i] == 'L' && cnt != 0) {
      ans += (cnt - 1);
      cnt = 0;
    }
    if (S[i] == 'R') {
      cnt += 1;
    }
  }

  // cout << ans << endl;

  // Lによるポイント
  cnt = 0;
  rep(i, 0, N+2) {
    if (S2[i] == 'R' && cnt != 0) {
      ans += (cnt - 1);
      cnt = 0;
    }
    if (S[i] == 'L') {
      cnt += 1;
    }
  }

  // cout << ans << endl;


  vector<int> block;
  // L block
  cnt = 0;
  int l, r;
  l = r = 0;
  rep(i, 0, N+2) {
    if (S2[i] == 'L') {
      if (cnt == 0) {
        l = i;
        r = i+1;
        cnt += 1;
      } else {
        cnt += 1;
        r = i+1;
      }
    } else {
      if (cnt == 0) continue;
      cnt = 0;
      int point;
      if (l == 1 && r == N + 1) {
        point = 0;
      } else if (l == 1 || r == N + 1) {
        point = 1;
      } else {
        point = 2;
      }
      block.pb(point);
    }
  }

  // for (auto p: block) {
  //   cout << p << endl;
  // }
  // cout << "---" << endl;

  // R block
  cnt = 0;
  l = r = 0;
  rep(i, 0, N+2) {
    if (S1[i] == 'R') {
      if (cnt == 0) {
        l = i;
        r = i+1;
        cnt += 1;
      } else {
        cnt += 1;
        r = i+1;
      }
    } else {
      if (cnt == 0) continue;
      cnt = 0;
      int point;
      if (l == 1 && r == N + 1) {
        point = 0;
      } else if (l == 1 || r == N + 1) {
        point = 1;
      } else {
        point = 2;
      }
      block.pb(point);
    }
  }

  // for (auto p: block) {
  //   cout << p << endl;
  // }
  // cout << "---" << endl;


  sort(All(block));
  reverse(All(block));

  rep(i, 0, block.size()) {
    if (i + 1 <= K) {
      ans += block[i];
    }
  }

  cout << ans << endl;

};
