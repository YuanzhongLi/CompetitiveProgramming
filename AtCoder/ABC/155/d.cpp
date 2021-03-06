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

const ll INF = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n, k;
  cin >> n >> k;
  vl A(n);
  ll zero_cnt = 0;
  vl pos, neg;

  rep(i, 0, n) {
    cin >> A[i];
    if (A[i] == 0ll) zero_cnt++;
    if (A[i] > 0ll) pos.pb(A[i]);
    if (A[i] < 0ll) neg.pb(A[i]);
  }

  sort(All(pos)); sort(All(neg));

  ll tot_pair = n*(n-1ll)/2ll;
  ll zero_pair = zero_cnt*(zero_cnt-1)/2ll + zero_cnt * (n - zero_cnt);

  ll neg_pair = (ll)pos.size() * (ll)neg.size();
  ll pos_pair = tot_pair - neg_pair - zero_pair;

  if (k <= neg_pair) {
    ll ok = -INF;
    ll ng = 0;

    bool flag;
    auto check = [&] (ll mid) {
      ll cnt = 0;
      rep(i, 0, pos.size()) {
        ll p = pos[i];
        ll q = -((abs(mid-1)+p-1) / p) + 1;
        ll idx = lbidx(neg, q);
        cnt += idx;
      }

      if (cnt < k) {
        flag = true;
      } else {
        flag = false;
      }
    };

    while (abs(ok - ng) > 1ll) {
      ll mid = (ok + ng) / 2ll;
      check(mid);
      if (flag) {
        ok = mid;
      } else {
        ng = mid;
      }
    }

    cout << ok << endl;

  } else if (k <= neg_pair + zero_pair) {
    cout << 0 << endl;
  } else {
    ll K = k - (neg_pair + zero_pair);

    rep(i, 0, neg.size()) {
      neg[i] = abs(neg[i]);
    }

    reverse(All(neg));

    ll ok = 1;
    ll ng = INF;



    bool flag;
    auto check = [&] (ll mid) {
      ll pp_cnt = 0;
      rep(i, 0, pos.size()) {
        ll q = (mid - 1) / pos[i] + 1;
        ll idx = lbidx(pos, q);
        pp_cnt += idx;
        if (pos[i] * pos[i] < mid) pp_cnt--;
      }
      pp_cnt /= 2ll;

      ll nn_cnt = 0;
      rep(i, 0, neg.size()) {
        ll q = (mid - 1) / neg[i] + 1;
        ll idx = lbidx(neg, q);
        nn_cnt += idx;
        if (neg[i] * neg[i] < mid) nn_cnt--;
      }

      nn_cnt /= 2ll;

      ll cnt = pp_cnt + nn_cnt;
      if (cnt < K) {
        flag = true;
      } else {
        flag = false;
      }
    };

    while (abs(ok - ng) > 1ll) {
      ll mid = (ok + ng) / 2ll;
      check(mid);
      if (flag) {
        ok = mid;
      } else {
        ng = mid;
      }
    }

    cout << ok << endl;
  }



  return 0;
};
