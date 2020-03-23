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

bool solve(vector<int> a, vector<int> p, set<int> p_set) {
  rep(i, 0, a.size()-1) {
    rep(j, 0, a.size() - 1) {
      int cur = a[j];
      int next = a[j+1];
      if (cur > next) {
        auto it = p_set.find(j);
        if (it != p_set.end()) {
          swap(a[j], a[j+1]);
        }
      }
    }
  }

  rep(i, 0, a.size()-1) {
    int cur = a[i];
    int next = a[i+1];
    if (cur > next) {
      return false;
    }
  }

  return true;
};

int main() {
  int t;
  cin >> t;
  vector<bool> ans(t, true);

  int n, m;
  rep(i, 0, t) {
    cin >> n >> m;
    vector<int> a(n);
    vector<int> p(m);
    set<int> p_set;

    rep(j, 0, n) {
      cin >> a[j];
    }

    rep(j, 0, m) {
      cin >> p[j];
      p[j] = p[j]-1;
      p_set.insert(p[j]);
    }

    ans[i] = solve(a, p, p_set);
  }

  rep(i, 0, t) {
    if (ans[i]) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
};
