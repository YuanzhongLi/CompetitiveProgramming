#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define ld long double
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
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << "\n";
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define endl "\n"
// gcj print用
#define Case(x) printf("Case #%d: ", x);

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<int>>> vvvl;
typedef vector<PI> vpi;
typedef vector<vector<PI>> vvpi;
typedef vector<vector<vector<PI>>> vvvpi;
typedef vector<PLL> vpl;
typedef vector<vector<PLL>> vvpl;
typedef vector<vector<vector<PLL>>> vvvpl;

int POWINT(int x, int n) {
  int ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
};

ll POWLL(ll x, int n) {
  ll ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
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

void print() {
  cout << endl;
}

template <class T>
void print(vector<T> &vec) {
  for (auto& a : vec) {
    cout << a;
    if (&a != &vec.back()) cout << " ";
  }
  cout << endl;
}

template <class T>
void print(vector<T> &vec, ll k){
   ll n = vec.size();
   k = min(k, n);
   rep(i, 0, k-1) cout << vec[i] << " ";
   cout << vec[k-1] << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
  for (auto& vec : df) {
    print(vec);
  }
}

template<class T, class U>
void print(pair<T,U> &p){
  cout << p.first << " " << p.second << "\n";
}

int s2i(string time, int type) {
  int ret = 0;
  rep(i, 0, 4) {
    ret += ((int)time[3-i]-'0')*POWINT(10, i);
  }

  int tmp = ret % 10;
  if (type == 0) {
    if (tmp >= 6) {
      ret /= 10;
      ret *= 10;
      ret += 5;
    } else if (1 <= tmp && tmp <= 4) {
      ret /= 10;
      ret *= 10;
    }
  } else {
    if (tmp >= 6) {
      ret /= 10;
      ret *= 10;
      ret += 10;
    } else if (1 <= tmp && tmp <= 4) {
      ret /= 10;
      ret *= 10;
      ret += 5;
    }
  }

  if (ret % 100 == 60) {
    ret += 40;
  }

  return ret;
};

PI s2pi(string s) {
  int fi = s2i(string(s.begin(), s.begin()+4), 0);
  int se = s2i(string(s.begin()+5, s.end()), 1);
  PI ret(fi, se);
  return ret;
};

void OUT(int x) {
  vi tmp(4);
  rep(i, 0, 4) {
    tmp[i] = x % 10;
    x /= 10;
  }
  reverse(All(tmp));
  for (auto i: tmp) {
    cout << i;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N; cin >> N;

  vi Table(2402, 0);
  rep(i, 0, N) {
    string s;
    cin >> s;
    PI pi = s2pi(s);
    Table[pi.first] += 1;
    Table[pi.second+1] -= 1;
  }

  rep(i, 1, 2402) {
    Table[i] += Table[i-1];
  }

  bool tmp = false;
  int s, t;
  vpi ans;
  rep(i, 0, 2402) {
    if (!tmp) {
      if (Table[i] > 0) {
        s = i;
        tmp = true;
      }
    } else {
      if (Table[i] == 0) {
        t = i-1;
        tmp = false;
        ans.pb(make_pair(s, t));
      }
    }
  }

  for (auto pi: ans) {
    OUT(pi.first);
    cout << "-";
    OUT(pi.second);
    cout << endl;
  }

  return 0;
};
