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

string prefixPail(string &s) {
  int len = 0;
  string ret = "";
  rep(i, 1, s.size()) { // 先頭のi-1文字目までがpalindrome
    bool flag = true;
    rep(j, 0, (i+1)/2) {
      if (s[j] != s[i-j]) flag = false;
    }
    if (flag) {
      len = i;
    }
  }
  len++;
  rep(i, 0, len) {
    ret += s[i];
  }

  // cout << s << endl;
  // cout << ret << endl;
  // cout << "----" << endl;
  return ret;
};

string solve(string &s) {
  int n = s.size();
  string re_s = "";
  rep(i, 0, s.size()) {
    re_s += s[n-1-i];
  }

  string prefix_s = prefixPail(s);
  string suffix_s = prefixPail(re_s);

  if ((int)prefix_s.size() == n) return s;

  string tmp;
  if (prefix_s.size() > suffix_s.size()) {
    tmp = prefix_s;
  } else {
    tmp = suffix_s;
  }

  int b_len = 0;
  string b_s = "";
  {
    int s_idx, e_idx;
    rep(i, 0, (int)s.size() / 2) {
      if (s[i] == re_s[i]) {
        b_len+=2;
      } else {
        s_idx = i;
        e_idx = n - i;
        break;
      }
    }


    if (b_len > 0)  {
      rep(i, 0, s_idx) {
        b_s += s[i];
      }
      // cout << s_idx << " " << e_idx << endl;

      string b_pre = string(s.begin()+s_idx, s.begin()+e_idx);
      string b_suf = string(re_s.begin()+s_idx, re_s.begin()+e_idx);
      // cout << b_pre << endl;
      // cout << b_suf << endl;

      string b_pre_s = prefixPail(b_pre);
      string b_suf_s = prefixPail(b_suf);
      if (b_pre_s.size() > b_suf_s.size()) {
        b_len += (int) b_pre_s.size();
        b_s += b_pre_s;
      } else {
        b_len += (int) b_suf_s.size();
        b_s += b_suf_s;
      }

      rep(i, 0, s_idx) {
        b_s += re_s[s_idx - 1 - i];
      }
    }
  }

  if (b_s.size() > tmp.size()) {
    return b_s;
  } else {
    return tmp;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  rep(i, 0, t) {
    string s;
    cin >> s;
    cout << solve(s) << endl;
  }

  return 0;
};
