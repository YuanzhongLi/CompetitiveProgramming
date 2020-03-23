#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j

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
    // 節点追加
    void addNode(int x) {
      par[x] = x;
      rank[x] = 0;
      size[x] = 1;
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

int main() {
  int N, M;
  cin >> N >> M;
  int x, y, z;

  Unionfind uf(N);

  rep(i, 0, M) {
    cin >> x >> y >> z;
    x--; y--;
    if (!uf.same(x, y)) {
      uf.unite(x, y);
    }
  }

  cout << uf.treeNum << endl;
};
