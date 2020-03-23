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

pair<vector<char>, vector<int>> Block(string s) {
  int num = 1;

  vector<char> v1;
  vector<int> v2;

  rep (i, 0, s.size()) {
    char c = s[i];
    if (i == 0) {
      v1.pb(c);
    } else if (c == s[i - 1]) {
      num++;
    } else {
      v2.pb(num);
      v1.pb(c);
      num = 1;
    }

    if (i == s.size() - 1) v2.pb(num);
  }

  return make_pair(v1, v2);
};

int main() {
  string s, t;
  cin >> s >> t;
  auto block_s = Block(s);
  auto ch_s = block_s.first;
  auto num_s = block_s.second;
  auto block_t = Block(t);
  auto ch_t = block_t.first;
  auto num_t = block_s.second;
  if (ch_s.size() != ch_t.size()) {
    cout << "No" << endl;
    return 0;
  }

  bool flag = true;
  map<int, int> m_s;
  map<int, int> m_t;
  rep(i, 0, ch_s.size()) {
    if (num_s[i] != num_t[i]) {
      flag = false;
      break;
    }
    int i_s = (int) ch_s[i];
    int i_t = (int) ch_t[i];

    if (Find(m_s, i_s)) {
      if (m_s[i_s] != i_t) {
        flag = false;
        break;
      }
    } else {
      m_s.emplace(i_s, i_t);
    }

    if (Find(m_t, i_t)) {
      if (m_t[i_t] != i_s) {
        flag = false;
        break;
      }
    } else {
      m_t.emplace(i_t, i_s);
    }
  }

  if (flag) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
};
