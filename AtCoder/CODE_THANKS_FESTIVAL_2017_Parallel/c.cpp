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

class M {
  public:
  ll a, b, cost;
  M(ll a, ll b, ll cost): a(a), b(b), cost(cost) {}
  bool operator < (const M &m) const {
    return cost > m.cost;
  }
};

int main() {
  int N, K;
  cin >> N >> K;
  priority_queue<M> pq;
  ll a, b;
  rep(i, 0, N) {
    cin >> a >> b;
    M m = M(a, b, a);
    pq.push(m);
  }

  ll ans = 0;
  rep(i, 0, K) {
    auto m = pq.top(); pq.pop();
    // cout << "m.cost: " << m.cost << " m.a: " << m.a << " m.b: " << m.b << endl;
    ans += m.cost;
    pq.push(M(m.a, m.b, m.cost += m.b));
  }

  cout << ans << endl;
};
