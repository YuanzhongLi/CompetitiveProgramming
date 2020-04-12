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
#define Case(x) cout << "Case #" << x << ": ";

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
  rep(i, 0, n) ret *= x;
  return ret;
};

ll POWLL(ll x, int n) {
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  rep(t, 0, T) {
    int n;
    cin >> n;
    vector<string> tmp(n);
    vector<vector<string>> P(n);
    int ma = 0;
    rep(i, 0, n) {
      string tmp_s;
      cin >> tmp_s;
      string tmp_s2 = "";
      tmp_s2 += tmp_s[0];
      rep(j, 1, tmp_s.size()) {
        if (tmp_s[j] == '*' && tmp_s[j-1] == '*') continue;
        tmp_s2 += tmp_s[j];
      }

      tmp_s2 = '1' + tmp_s2;
      tmp_s2 += '1';

      vector<string> tmp_vec;
      rep(i, 0, tmp_s2.size()) {
        string tmp_s3 = "";
        while (i < tmp_s2.size()) {
          if (tmp_s2[i] != '*') {
            tmp_s3 += tmp_s2[i];
            i++;
          } else {
            break;
          }
        }
        if (tmp_s3.size() > 0) {
          tmp_vec.pb(tmp_s3);
        }
      }
      // PrintVec(tmp_vec);
      P[i] = tmp_vec;
      ma = max(ma, (int)tmp_vec.size());
    }

    rep(i, 0, n) {
      if (P[i].size() == ma) continue;
      vector<string> new_vec(ma, "1");
      rep(j, 0, P[i].size()-1) {
        new_vec[j] = P[i][j];
      }
      new_vec[ma-1] = P[i][P[i].size()-1];
      P[i] = new_vec;
    }

    bool front_ok = true, back_ok = true;
    string front_base = "", back_base = "";
    rep(i, 0, n) {
      if (P[i][0].size() > front_base.size()) {
        front_base = P[i][0];
      }
      if (P[i][ma-1].size() > back_base.size()) {
        back_base = P[i][ma-1];
      }
    }

    rep(i, 0, n) {
      string pi0 = P[i][0];
      string pima = P[i][ma-1];
      rep(j, 0, pi0.size()) {
        if (pi0[j] != front_base[j]) {
          front_ok = false;
          break;
        }
      }
      rep(j, 0, pima.size()) {
        if (pima[pima.size()-1 - j] != back_base[back_base.size()-1 -j]) {
          back_ok = false;
          break;
        }
      }
    }
    if (front_ok && back_ok) {
      string ans = "";
      rep(i, 1, front_base.size()) {
        ans += front_base[i];
      }
      rep(j, 1, ma-1) {
        string tmp = "";
        rep(i, 0, n) {
          if (P[i][j] == "1") continue;
          tmp += P[i][j];
        }
        ans += tmp;
      }
      rep(i, 0, back_base.size()-1) {
        ans += back_base[i];
      }
      Case(t+1);
      cout << ans << endl;
    } else {
      Case(t+1);
      cout << '*' << endl;
    }
  }


  return 0;
};
