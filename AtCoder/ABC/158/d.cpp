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

struct Query {
  int T, F;
  char C;
  int cnt;
};

int main() {
  string s;
  cin >> s;
  int Q;
  cin >> Q;
  vector<char> front;
  vector<char> back;

  vector<Query> query(Q);
  int T;
  int F;
  char C;
  rep(i, 0, Q) {
    cin >> T;
    if (T == 1) {
      query[i].T = 1;
    } else {
      query[i].T = 2;
      cin >> F >> C;
      query[i].F = F;
      query[i].C = C;
    }
  }

  reverse(All(query));

  int reverse_cnt = 0;
  rep(i, 0, Q) {
    if (query[i].T == 1) {
      reverse_cnt++;
    }
    if (query[i].T == 2) {
      query[i].cnt = reverse_cnt;
    }
  }

  if (reverse_cnt % 2 == 1) {
    reverse(All(s));
  }

  reverse(All(query));

  // rep(i, 0, Q) {
  //   cout << query[i].T << " " << query[i].F << " " << query[i].C << " " << query[i].cnt << endl;
  // }

  rep(i, 0, Q) {
    auto q = query[i];
    if (q.T == 2) {
      if (q.F == 1) {
        if (q.cnt % 2 == 0) {
          front.pb(q.C);
        }
        if (q.cnt % 2 == 1) {
          back.pb(q.C);
        }
      }
      if (q.F == 2) {
        if (q.cnt % 2 == 0) {
          back.pb(q.C);
        }
        if (q.cnt % 2 == 1) {
          front.pb(q.C);
        }
      }
    }
  }

  reverse(All(front));
  vector<char> ans;

  rep(i, 0, front.size()) {
    ans.pb(front[i]);
  }
  rep(i, 0, s.size()) {
    ans.pb(s[i]);
  }
  rep(i, 0, back.size()) {
    ans.pb(back[i]);
  }

  rep(i, 0, ans.size()) {
    cout << ans[i];
  }
  cout << endl;
  return 0;
};
