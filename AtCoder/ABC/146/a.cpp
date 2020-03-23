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
  string S;
  cin >> S;
  if (S == "SUN") {
    cout << 7 << endl;
  } else if (S == "MON") {
    cout << 6 << endl;
  } else if (S == "TUE") {
    cout << 5 << endl;
  }else if (S == "WED") {
    cout << 4 << endl;
  }else if (S == "THU") {
    cout << 3 << endl;
  }else if (S == "FRI") {
    cout << 2 << endl;
  }else if (S == "SAT") {
    cout << 1 << endl;
  }
  return 0;
};
