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

pair<vector<char>, vector<ll>> Block(string s) {
  ll num = 1;

  vector<char> v1;
  vector<ll> v2;

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

ll calc(vector<char> &b_ch, vector<ll> &b_num) {
  ll ans = 0;
  rep(i, 0, (int)b_ch.size()) {
    ll n = b_num[i];
    char ch = b_ch[i];
    if (ch == '<' && i < (int)b_ch.size()-1) {
      ans += (n)*(n-1ll)/2ll;
    } else if (ch == '>') {
      ll m = b_num[i-1]; // left '<'
      if (m > n) {
        ans += (n)*(n-1ll)/2ll + m;
      } else {
        ans += (n+1ll)*n/2ll;
      }
    } else if (ch == '<' && i == b_ch.size() - 1){
      ans += (n+1ll)*n/2ll;
    }
  }

  return ans;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string S;
  cin >> S;

  auto block = Block(S);

  auto b_ch = block.first;
  auto b_num = block.second;

  // PrintVec(b_ch);
  // PrintVec(b_num);


  if (S[0] == '<') {
    ll ans = calc(b_ch, b_num);
    cout << ans << endl;
    return 0;
  }

  if (S[0] == '>') {
    vector<char> b_ch2 = vector<char> (b_ch.begin()+1, b_ch.end());
    vector<ll> b_num2 = vector<ll> (b_num.begin()+1, b_num.end());
    ll ans = calc(b_ch2, b_num2);
    ll n0 = b_num[0];
    ans += (n0+1ll)*n0/2ll;
    cout << ans << endl;
    return 0;
  }

  return 0;
};
