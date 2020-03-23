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

int isPrime(int x) {
  int i;
  if (x < 2) return 0;
  else if (x == 2) return 1;

  if (x % 2 == 0) return 0;
  for (i = 3; i*i <= x; i += 2) {
    if (x % i == 0) return 0;
  }
  return 1;
};

map<int, int> PrimeFactorization(int x, vector<int> &pn) {
  map<int, int> ret;
  rep(i, 0, pn.size()) {
    ret.emplace(pn[i], 0);
  }

  int pn_idx = 0;
  while(x > 1) {
    int p = pn[pn_idx];
    if (x % p == 0) {
      x /= p;
      ret[p]++;
    } else {
      pn_idx++;
    }
  }

  return ret;
};

int main() {
  int N;
  cin >> N;

  vector<int> primeNumbers;
  rep(i, 2, 101) {
    if (isPrime(i)) {
      primeNumbers.pb(i);
    }
  }

  // 1!から100!を素因数分解
  vector<map<int, int>> PFS(101);
  for (int p: primeNumbers) {
    PFS[1].emplace(p, 0);
  }

  rep(i, 2, 101) {
    auto i_PF = PrimeFactorization(i, primeNumbers);
    for (auto p: primeNumbers) {
      PFS[i].emplace(p, PFS[i-1][p] + i_PF[p]);
    }
  }

  // N!の素因数分解
  auto N_PF = PFS[N];

  vector<int> v;
  for (auto p: primeNumbers) {
    v.pb(N_PF[p]);
  }

  sort(All(v));
  // PrintVec(v);

  int ans = 0;
  // 1, 75
  {
    rep(i, 0, v.size()) {
      if (v[i] >= 74) {
        ans += 1;
      }
    }
  }


  // 25, 3
  {
    vector<int> tmp25;
    vector<int> tmp3;
    rep(i, 0, v.size()) {
      if (v[i] >= 24) {
        tmp25.pb(i);
      }
      if (v[i] >= 2) {
        tmp3.pb(i);
      }
    }

    rep(i, 0, tmp25.size()) {
      int t25 = tmp25[i];
      rep(j, 0, tmp3.size()) {
        int t3 = tmp3[j];
        if (t25 != t3) {
          ans++;
        }
      }
    }
  }

  // 15, 5
  {
    vector<int> tmp15;
    vector<int> tmp5;
    rep(i, 0, v.size()) {
      if (v[i] >= 14) {
        tmp15.pb(i);
      }
      if (v[i] >= 4) {
        tmp5.pb(i);
      }
    }
    rep(i, 0, tmp15.size()) {
      int t15 = tmp15[i];
      rep(j, 0, tmp5.size()) {
        int t5 = tmp5[j];
        if (t15 != t5) {
          ans++;
        }
      }
    }
  }

  // 3, 5, 5
  {
    vector<int> tmp3;
    vector<int> tmp5;
    rep(i, 0, v.size()) {
      if (v[i] >= 4) {
        tmp5.pb(i);
        tmp3.pb(i);
      } else if (v[i] >= 2) {
        tmp3.pb(i);
      }
    }
    if (tmp5.size() >= 2) {
      rep(i, 0, tmp5.size() - 1) {
        rep(j, i+1, tmp5.size()) {
          int t_i = tmp5[i];
          int t_j = tmp5[j];
          rep(k, 0, tmp3.size()) {
            int t_k = tmp3[k];
            if ((t_k != t_i) && (t_k != t_j)) {
              ans++;
            }
          }
        }
      }
    }
  }

  cout << ans << endl;

  // PrintVec(primeNumbers);

  return 0;
};
