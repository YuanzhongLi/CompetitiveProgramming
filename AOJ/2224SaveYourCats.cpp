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

class Unionfind {
  public:
    vector<int> par; // 節点
    vector<int> rank; // 木の高さ
    vector<int> size; // 節点が属する木の節点数
    int treeNum; // 木の数
    Unionfind(int N) : par(N), rank(N, 0), size(N, 1) {
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
      treeNum--;
      if (x == y) {
        return;
      }
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
};

class Edge {
  public:
    int source, target;
    double cost;
    Edge() {}
    Edge(int source, int target, double cost): source(source), target(target), cost(cost) {}
    bool operator < (const Edge &e) const {
      return cost < e.cost;
    }
};

double Kruskal (int N, vector<Edge> &edges) {
  double totalCost = 0ll;
  sort(All(edges));
  Unionfind uf = Unionfind(N);

  rep(i, 0, edges.size()) {
    Edge e = edges[i];
    if (!uf.same(e.source, e.target)) {
      totalCost += e.cost;
      uf.unite(e.source, e.target);
    }
  }

  return totalCost;
};

struct Pile {
  double x, y;
};

double dis(Pile p1, Pile p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  double total_cost = 0.0;
  vector<Pile> piles(N);

  rep(i, 0, N) {
    cin >> piles[i].x >> piles[i].y;
  }

  int u, v;
  double cost;
  vector<Edge> edges;
  rep(i, 0, M) {
    cin >> u >> v;
    u--; v--;
    cost = dis(piles[u], piles[v]);
    total_cost += cost;
    Edge e1 = Edge(u, v, -cost);
    Edge e2 = Edge(v, u, -cost);
    edges.pb(e1);
    edges.pb(e2);
  }

  double neg_cost = Kruskal(N, edges);
  // Decimal(neg_cost);
  double ans = total_cost + neg_cost;
  Decimal(ans);

  return 0;
};
