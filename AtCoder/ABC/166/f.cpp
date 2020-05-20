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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  int a, b, c;
  cin >> a >> b >> c;

  vector<string> vec(N);
  vector<char> ans(N);
  rep(i, 0, N) {
    string s;
    cin >> s;
    vec[i] = s;
  }

  if (a + b + c == 0) {
    cout << "No" << endl;
  } else if (a + b + c == 1) {
    bool ok = true;
    rep(i, 0, N) {
      string s = vec[i];
      if (s == "AB") {
        if (a > b) {
          a--; b++; ans[i] = 'B';
        } else {
          a++; b--; ans[i] = 'A';
        }
      } else if (s == "AC") {
        if (a > c) {
          a--; c++; ans[i] = 'C';
        } else {
          a++; c--; ans[i] = 'A';
        }
      } else if (s == "BC") {
        if (b > c) {
          b--; c++; ans[i] = 'C';
        } else {
          b++; c--; ans[i] = 'B';
        }
      }
      if (a < 0 || b < 0 || c < 0) {
        ok = false;
        break;
      }
    }

    if (ok) {
      cout << "Yes" << endl;
      rep(i, 0, N) {
        cout << ans[i] << endl;
      }
    } else {
      cout << "No" << endl;
    }
  } else {
    int tot = a + b + c;
    bool ok = true;
    rep(i, 0, N-1) {
      string s = vec[i];
      string nxt = vec[i+1];
      if (s == "AB") {
        if (a == 0) {
          a++; b--; ans[i] = 'A';
        } else if (b == 0) {
          a--; b++; ans[i] = 'B';
        } else if (tot == 2) {
          if (nxt == "AC") {
            a++; b--; ans[i] = 'A';
          } else if (nxt == "BC") {
            b++; a--; ans[i] = 'B';
          } else {
            if (a > b) {
              a--; b++; ans[i] = 'B';
            } else {
              a++; b--; ans[i] = 'A';
            }
          }
        } else {
          if (a > b) {
            a--; b++; ans[i] = 'B';
          } else {
            a++; b--; ans[i] = 'A';
          }
        }
      } else if (s == "AC") {
        if (a == 0) {
          a++; c--; ans[i] = 'A';
        } else if (c == 0) {
          a--; c++; ans[i] = 'C';
        } else if (tot == 2) {
          if (nxt == "AB") {
            a++; c--; ans[i] = 'A';
          } else if (nxt == "BC") {
            c++; a--; ans[i] = 'C';
          } else {
            if (a > c) {
              a--; c++; ans[i] = 'C';
            } else {
              a++; c--; ans[i] = 'A';
            }
          }
        } else {
          if (a > c) {
            a--; c++; ans[i] = 'C';
          } else {
            a++; c--; ans[i] = 'A';
          }
        }
      } else if (s == "BC") {
        if (b == 0) {
          b++; c--; ans[i] = 'B';
        } else if (c == 0) {
          b--; c++; ans[i] = 'C';
        } else if (tot == 2) {
          if (nxt == "AC") {
            c++; b--; ans[i] = 'C';
          } else if (nxt == "BC") {
            b++; c--; ans[i] = 'B';
          } else {
            if (b > c) {
              b--; c++; ans[i] = 'C';
            } else {
              b++; c--; ans[i] = 'B';
            }
          }
        } else {
          if (b > c) {
            b--; c++; ans[i] = 'C';
          } else {
            b++; c--; ans[i] = 'B';
          }
        }
      }
      if (a < 0 || b < 0 || c < 0) {
        ok = false;
        break;
      }
    }

    string s = vec[N-1];
    if (s == "AB") {
      if (a > b) {
        a--; b++; ans[N-1] = 'B';
      } else {
        a++; b--; ans[N-1] = 'A';
      }
    } else if (s == "AC") {
      if (a > c) {
        a--; c++; ans[N-1] = 'C';
      } else {
        a++; c--; ans[N-1] = 'A';
      }
    } else if (s == "BC") {
      if (b > c) {
        b--; c++; ans[N-1] = 'C';
      } else {
        b++; c--; ans[N-1] = 'B';
      }
    }

    if (a < 0 || b < 0 || c < 0) {
      ok = false;
    }

    if (ok) {
      cout << "Yes" << endl;
      rep(i, 0, N) {
        cout << ans[i] << endl;
      }
    } else {
      cout << "No" << endl;
    }
  }




  return 0;
};
