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

class Unionfind {
  public:
    int N;
    vector<int> par; // 節点
    vector<int> rank; // 木の高さ
    vector<int> size; // 節点が属する木の節点数
    int treeNum; // 木の数
    Unionfind(int N) : N(N), par(N), rank(N, 0), size(N, 1) {
      for (int i = 0; i < N; i++) {
        par[i] = i;
      }
      treeNum = N;
    }
    // 節点(木)追加
    void addNode(int x) {
      par[x] = x;
      rank[x] = 0;
      size[x] = 1;
      treeNum++;
    }
    // 根を探すと同時に経路上にある節点の親が根になるように代入
    int root(int x) {
      return par[x] == x ? x : par[x] = root(par[x]);
    }
    // 同じ木に属しているか
    bool same(int x, int y) {
      return root(x) == root(y);
    }
    // rankが低い方の木をrankが高い方の木の根に結びつける(結びつけた後の新しい木の高さが高くなることがないため)
    void unite(int x, int y) {
      x = root(x);
      y = root(y);
      if (x == y) {
        return;
      }
      treeNum--;
      if (rank[x] < rank[y]) {
        par[x] = y;
        size[y] += size[x];
      } else {
        par[y] = x;
        size[x] += size[y];
        if (rank[x] == rank[y]) {
          rank[x] += 1;
        }
      }
    }

    vector<vector<int>> group() { // 二重ループだが実はO(N)
      vector<vector<int>> res; // 実はresの全体のサイズはN
      vector<bool> fixed(N, false);
      for (int i = 0; i < N; i++) {
        if (!fixed[i]) {
          vector<int> tmp;
          for (int j = i; j < N; j++) {
            if (same(i, j)) {
              tmp.push_back(j);
              fixed[j] = true;
            }
          }
          res.push_back(tmp);
        }
      }

      return res;
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k, l;
  cin >> n >> k >> l;
  Unionfind k_uf(n), l_uf(n);

  vpi pq(k), rs(l);
  int p, q;
  rep(i, 0, k) {
    cin >> p >> q;
    p--; q--;
    k_uf.unite(p, q);
  }

  int r, s;
  rep(i, 0, l) {
    cin >> r >> s;
    r--; s--;
    l_uf.unite(r, s);
  }

  map<PI, int> mp;
  rep(i, 0, n) {
    mp[make_pair(k_uf.root(i), l_uf.root(i))]++;
  }

  rep(i, 0, n) {
    cout << mp[make_pair(k_uf.root(i), l_uf.root(i))];
    if (i < n - 1) {
      cout << " ";
    }
  }

  cout << endl;


  return 0;
};
