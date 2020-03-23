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
  int N, M;
  cin >> N >> M;
  vector<int> cntwa(N+1, 0);
  int wa_ans = 0;
  set<int> s;
  int p;
  string S;
  rep(i, 0, M) {
    cin >> p >> S;
    if (S == "AC") {
      // まだACしていない場合
      if (s.find(p) == s.end()) {
        s.insert(p);
        wa_ans += cntwa[p];
      }
    } else if (S == "WA") {
      cntwa[p]++;
    }
  }
  cout << (int)s.size() << " " << wa_ans << endl;
};
