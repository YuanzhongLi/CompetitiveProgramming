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
#define Decimal(x) printf("%.10f\n", x) // 小数点を10桁まで表示
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;

int POWINT(int x, int n) {
  int ret = 1;
  rep(i, 0, n) ret *= x;
  return ret;
};

ll POWLL(int x, int n) {
  ll ret = 1;
  rep(i, 0, n) ret *= x;
  return ret;
};

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

string solve(string aa, string bb) {
  string s;
  string a, b;
  if (aa.size() <= bb.size()) {
    a = aa;
    b = bb;
  } else {
    a = bb;
    b = aa;
  }
  rep(i, 0, a.size()) {
    string tmp = "";
    rep(j, 0, i) {
      tmp += a[j];
    }
    bool flag = true;
    rep (j, 0, min(b.size(), a.size() - i)) {
      if (a[i+j] == b[j]) {
        tmp += b[j];
      } else if (a[i+j] == '?') {
        tmp += b[j];
      } else if (b[j] == '?') {
        tmp += a[i+j];
      } else {
        flag = false;
        break;
      }
    }

    rep(j, min(b.size(), a.size() - i), b.size()) {
      tmp += b[j];
    }

    if (flag) {
      s = tmp;
      break;
    }
  }

  if (s.empty()) {
    s = a + b;
  }
  return s;
};

int main() {
  string a, b, c;
  cin >> a >> b >> c;
  string s1, s2, s3, s4, s5 ,s6;

  vector<string> ans;

  { // a b
    s1 = solve(a, b);
    {
      ans.pb(solve(s1, c));
      ans.pb(solve(c, s1));
    }
  }

  { // b a
    s2 = solve(b, a);
    {
      ans.pb(solve(s2, c));
      ans.pb(solve(c, s2));
    }
  }

  { // a c
    s3 = solve(a, c);
    {
      ans.pb(solve(b, s3));
      ans.pb(solve(s3, b));
    }
  }

  { // c a
    s4 = solve(c, a);
    {
      ans.pb(solve(s4, b));
      ans.pb(solve(b, s4));
    }
  }

  {
    // b c
    s5 = solve(b, c);
    {
      ans.pb(solve(s5, a));
      ans.pb(solve(a, s5));
    }
  }
  {
    // c b
    s6 = solve(c, b);
    {
      ans.pb(solve(s6, a));
      ans.pb(solve(a, s6));
    }
  }

  int A = 1 << 28;
  rep(i, 0, ans.size()) {
    // cout << ans[i] << endl;
    A = min((int)ans[i].size(), A);
  }

  cout << A << endl;

  return 0;
};
