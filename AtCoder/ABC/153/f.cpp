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

struct Node {
  ll value;
  ll lazy;
  Node () {
    value = lazy = 0ll;
  }
};

class LazySegTree {
  int n;
  vector<Node> dat;
  Node e;
public:
  LazySegTree(int n_) {
    n = 1;
    while (n < n_) { n*=2; }
    dat.resize(2*n);
    for (int i = 0; i < 2 * n - 1; i++) {
      dat[i] = e;
    }
  }
  // k番目のノードについて遅延評価を行う
  void eval(int k, int l, int r) {
    if (dat[k].lazy != 0ll) {
      dat[k].value += dat[k].lazy;
      // 最下段かどうかのcheck
      // 子ノードは親ノードの半分を伝播させる
      if (r - l > 1) {
        dat[2*k+1].lazy += dat[k].lazy / 2ll;
        dat[2*k+2].lazy += dat[k].lazy / 2l;
      }
      dat[k].lazy = 0ll;
    }
  }
  // [l, r)を更新
  void update(int a, int b, ll x, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n;

    // k番目のノードに対して遅延評価を行う
    eval(k, l, r);

    // 範囲外なら何もしない
    if (b <= l || r <= a) return;

    // 完全に覆っているなら、遅延に値を入れた後に評価
    if (a <= l && r <= b) {
      dat[k].lazy += (r - l) * x;
      eval(k, l, r);
    } else { // そうでないならば、子ノードの値を再帰的に計算して、計算済みの値をもらってくる
      update(a, b, x, 2*k+1, l, (l+r)/2);
      update(a, b, x, 2*k+2, (l+r)/2, r);
      dat[k].value = dat[2*k+1].value + dat[2*k+2].value;
    }
  }

  ll query(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n;
    if (b <= l || r <= a) return 0ll;
    // 関数が呼び出されたら評価
    eval(k, l, r);
    if (a <= l && r <= b) return dat[k].value;

    ll vl = query(a, b, 2*k+1, l, (l+r)/2);
    ll vr = query(a, b, 2*k+2, (l+r)/2, r);
    return vl + vr;
  }
};

class Enemy {
  public:
  int x;
  ll h;
  Enemy() {}
  Enemy(int x, ll h): x(x), h(h) {}
  bool operator < (const Enemy &e) const {
    return x < e.x;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  ll D, A;
  cin >> N >> D >> A;
  vector<Enemy> ens(N+1);
  rep(i, 0, N) {
    cin >> ens[i].x >> ens[i].h;
  }
  ens[N].x = 2e9+7;

  sort(All(ens));

  LazySegTree lst = LazySegTree(N);

  rep(i, 0, N) {
    lst.update(i, i+1, ens[i].h);
  }

  ll ans = 0;
  rep(i, 0, N) {
    int x = ens[i].x;
    ll hp = lst.query(i, i+1);
    if (hp <= 0ll) continue;

    int ok = i, ng = N;
    while (abs(ok - ng) > 1) {
      int mid = (ng + ok) / 2;
      if (ens[mid].x <= x+2*D) {
        ok = mid;
      } else {
        ng = mid;
      }
    }

    ll attack = (hp + A - 1) / A;
    lst.update(i, ok+1, -(attack*A));
    ans += attack;
  }

  cout << ans << endl;


  return 0;
};
