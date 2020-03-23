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

vector<int> manacher_for_odd(const string &s) {
  vector< int > radius(s.size());
  int i = 0, j = 0;
  while(i < s.size()) {
    while(i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]) {
      ++j;
    }
    radius[i] = j;
    int k = 1;
    while(i - k >= 0 && i + k < s.size() && k + radius[i - k] < j) {
      radius[i + k] = radius[i - k];
      ++k;
    }
    i += k;
    j -= k;
  }
  return radius;
}

vector<int> manacher_for_even(const string &s) {
  string tmp;
  rep(i, 0, s.size()) {
    char ch = s[i];
    tmp += ch;
    if (i < (int)s.size() - 1) {
      tmp += '$'; // 登場しない文字
    }
  }
  return manacher_for_odd(tmp);
};

// 0スタートでi番目の文字について
// iが偶数だとその数を含めての最長回文半径
// iが奇数だとその隙間からの最長回文半径
// O(|s|)
vector<int> manacher(const string &s) {
  vector<int> manacher_odd = manacher_for_odd(s);
  vector<int> manacher_even = manacher_for_even(s);
  vector<int> manacher_vec = vector<int> ((int)manacher_even.size());
  rep(i, 0, manacher_vec.size()) {
    if (i % 2 == 0) {
      manacher_vec[i] = manacher_odd[i/2];
    } else {
      manacher_vec[i] = manacher_even[i]/2;
    }
  }

  return manacher_vec;
};

// 左端からの極大回文を返す
// O(|s|)
string PrefixPalindrome(const string &s) {
  vector<int> manacher_vec = manacher(s);
  vector<int> ret((int)s.size(), 1);

  rep(i, 0, manacher_vec.size()) {
    int n = manacher_vec[i];
    if (i % 2 == 0) { // その数を含む
      int ret_idx = i / 2;
      n--;
      ret[ret_idx - n] = max(ret[ret_idx - n], n*2+1);
    } else {
      if (n == 0) continue;
      int ret_idx = i / 2;
      ret[ret_idx+1-n] = max(ret[ret_idx+1-n], 2*n);
    }
  }

  string s_ret = "";
  rep(i, 0, ret[0]) {
    s_ret += s[i];
  }

  return s_ret;
};

string solve(string &s) {
  int n = s.size();
  string re_s = s;
  reverse(All(re_s));

  string prefix_s = PrefixPalindrome(s);
  string suffix_s = PrefixPalindrome(re_s);

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

      string b_pre = string(s.begin()+s_idx, s.begin()+e_idx);
      string b_suf = string(re_s.begin()+s_idx, re_s.begin()+e_idx);

      string b_pre_s = PrefixPalindrome(b_pre);
      string b_suf_s = PrefixPalindrome(b_suf);
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
