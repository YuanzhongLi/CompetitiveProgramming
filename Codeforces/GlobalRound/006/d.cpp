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

class Deb {
  public:
    int u, v;
    ll d;
  Deb() {}
  Deb(int u, int v, ll d): u(u), v(v), d(d) {}
  bool operator < (const Deb &deb) const {
    return d < deb.d;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  int u, v;
  ll d;
  vector<ll> bal(n, 0ll);
  rep(i, 0, m) {
    cin >> u >> v >> d;
    u--; v--;
    bal[u] -= d;
    bal[v] += d;
  }

  vector<int> pos, neg;
  rep(i, 0, n) {
    if (bal[i] > 0ll) {
      pos.pb(i);
    } else if (bal[i] < 0ll) {
      neg.pb(i);
      bal[i] *= -1;
    }
  }

  vector<pair<pair<int, int>, ll>> ansl;

  int j = 0;
  for (auto x: pos) {
    while (j < neg.size()) {
      if (bal[x] < bal[neg[j]]) { // negより小さい時
        if (bal[x] > 0ll) {
          ansl.pb({{ x, neg[j]}, bal[x]});
          bal[neg[j]] -= bal[x]; // neg[j]を消費してbreak
        }
        break; // 次のxにいく
      } else { // posがneg以上のとき
        if (bal[neg[j]] > 0ll) {
          ansl.pb({{x, neg[j]}, bal[neg[j]]});
          bal[x] -= bal[neg[j]]; // neg[j]を全部消費して次のjへ
        }
        j++;
      }
    }
  }

  cout << ansl.size() << endl;

  for (auto r: ansl) {
    cout << r.first.second+1 << " " << r.first.first+1 << " " << r.second << endl;
  }

  return 0;
};
