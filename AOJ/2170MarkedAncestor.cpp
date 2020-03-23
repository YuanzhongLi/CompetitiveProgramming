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
    // xをrootとしてuniteする
    void optional_unite(int x, int y) {
      x = root(x);
      y = root(y);
      if (x == y) {
        return;
      }
      treeNum--;
      par[y] = x;
      size[x] += size[y];
      rank[x] = max(rank[x], rank[y]+1);
    }
};

template<class T>
inline bool chmin(T &a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
};

using P = pair<char, int>;

int root(int x, vector<int>& par, vector<int> const& cnt) {
  if(cnt[x] > 0) {
    return x;
  }
  return par[x] = root(par[x], par, cnt);
}

int main() {
  int N, Q;
  while(cin >> N >> Q, N) {
    vector<int> parent(N);
    for(int i=1; i<N; ++i) {
      int p;
      cin >> p;
      p--;
      parent[i] = p;
    }
    vector<P> query(Q);
    vector<int> m_cnt(N);
    m_cnt[0] = 1;
    for(int i=0; i<Q; ++i) {
      cin >> query[i].first >> query[i].second;
      query[i].second--;
      if(query[i].first == 'M') {
          m_cnt[query[i].second]++;
      }
    }
    reverse(query.begin(), query.end());
    long long res = 0;
    for(auto& q : query) {
      if(q.first == 'Q') {
          res += root(q.second, parent, m_cnt) + 1;
      } else {
          m_cnt[q.second]--;
      }
    }
    cout << res << endl;
  }
};
