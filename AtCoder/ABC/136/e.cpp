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

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;

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

vector<int> divisor(int n) {
  vector<int> ret;
  for(int i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(All(ret));
  reverse(All(ret));
  return (ret);
};

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  int total_A = 0;
  rep(i, 0, N) {
    cin >> A[i];
    total_A += A[i];
  }

  auto ds = divisor(total_A);
  int l, r;
  for (auto gcd: ds) {
    if (gcd == 1) {
      cout << gcd << endl;
      return 0;
    }

    vector<int> mod_A;
    rep(i, 0, N) {
      if (A[i] % gcd != 0) {
        mod_A.pb(A[i] % gcd);
      }
    }

    if (mod_A.empty()) {
      cout << gcd << endl;
      return 0;
    }

    sort(All(mod_A));

    vector<int> mod_A2;
    for (int ele: mod_A) {
      mod_A2.pb(gcd - ele);
    }

    reverse(All(mod_A2));

    vector<int> mod_A_total = mod_A;
    rep(i, 1, mod_A_total.size()) {
      mod_A_total[i] += mod_A_total[i-1];
    }

    vector<int> mod_A2_total = mod_A2;
    rep(i, 1, mod_A2_total.size()) {
      mod_A2_total[i] += mod_A2_total[i-1];
    }

    int size = mod_A_total.size();

    rep(i, 0, mod_A_total.size()-1) {
      int mod_A_cnt = mod_A_total[i];
      int mod_A2_cnt = mod_A2_total[size - 2 - i];
      if (mod_A_cnt == mod_A2_cnt && mod_A_cnt <= K) {
        cout << gcd << endl;
        return 0;
      }
    }
  }

  return 0;
};
