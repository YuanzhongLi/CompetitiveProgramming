#include <bits/stdc++.h>
using namespace std;

class Unionfind {
  public:
    vector<int> par; // 節点
    vector<int> rank; // 木の高さ
    vector<int> size; // 節点が属する木の節点数
    Unionfind(int N) : par(N), rank(N, 0), size(N, 1) {
      for (int i = 0; i < N; i++) {
        par[i] = i;
      }
    }
    // 節点追加
    void addPar(int x) {
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
  vector<vector<int>> data(M, vector<int>(2));
  for (int i = 0; i < M; i++) {
    cin >> data[i][0];
    cin >> data[i][1];
    data[i][0] -= 1;
    data[i][1] -= 1;
  }

  reverse(data.begin(), data.end());

  Unionfind uf(N);

  vector<long long> union_array(M);

  for (int i = 0; i < M; i++) {
    int x = uf.root(data[i][0]);
    int y = uf.root(data[i][1]);
    if (!uf.same(x, y)) {
      long long ans = uf.size[x] * uf.size[y];
      uf.unite(x, y);
      union_array[i] = ans;
    } else {
      union_array[i] = 0;
    }
  }

  reverse(union_array.begin(), union_array.end());

  long long op = 0;

  for (int i = 0; i < M; i++) {
    op += union_array[i];
    cout << op << endl;
  }
};
