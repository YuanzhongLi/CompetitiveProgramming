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

string table[16] = {
  "NNE",
  "NE",
  "ENE",
  "E",
  "ESE",
  "SE",
  "SSE",
  "S",
  "SSW",
  "SW",
  "WSW",
  "W",
  "WNW",
  "NW",
  "NNW",
  "N",
};

string DEG(int deg) {
  rep(i, 0, 15) {
    if (1125 + i * 2250 <= deg && deg < 1125 + (i+1) * 2250) {
      return table[i];
    }
  }
  return table[15];
};

int DIS(int dis) {
  if (0 <= dis && dis <= 24) {
    return 0;
  } else if (25 <= dis && dis <= 154) {
    return 1;
  } else if (155 <= dis && dis <= 334) {
    return 2;
  } else if (335 <= dis && dis <= 544) {
    return 3;
  } else if (545 <= dis && dis <= 794) {
    return 4;
  } else if (795 <= dis && dis <= 1074) {
    return 5;
  } else if (1075 <= dis && dis <= 1384) {
    return 6;
  } else if (1385 <= dis && dis <= 1714) {
    return 7;
  } else if (1715 <= dis && dis <= 2074) {
    return 8;
  } else if (2075 <= dis && dis <= 2444) {
    return 9;
  } else if (2445 <= dis && dis <= 2844) {
    return 10;
  } else if (2845 <= dis && dis <= 3264) {
    return 11;
  } else {
    return 12;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int deg, dis;
  cin >> deg >> dis;
  deg *= 10;

  dis *= 100;
  dis /= 60;
  if (DIS(dis) > 0) {
    cout << DEG(deg) << " " << DIS(dis) << endl;
  } else {
    cout << "C" << " " << 0 << endl;
  }


  return 0;
};
