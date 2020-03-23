#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define llbidx(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y) // 二要素間の距離
#define deg2rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad2deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)
#define Find(set, element) set.find(element) != set.end()

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

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<int>> graph_m(N);
  vector<vector<int>> graph_k(N);
  vector<set<int>> set_k(N);

  int A, B;
  rep(i, 0, M) {
    cin >> A >> B;
    A--; B--;
    graph_m[A].pb(B);
    graph_m[B].pb(A);
  }

  int C, D;
  rep(i, 0, K) {
    cin >> C >> D;
    C--; D--;
    graph_k[C].pb(D);
    graph_k[D].pb(C);
    set_k[C].insert(D);
    set_k[D].insert(C);
  }

  vector<bool> color(N, false);

  vector<int> ans(N, 0);

  rep(i, 0, N) {
    vector<int> tree;
    set<int> s_tree;

    int u = i;
    queue<int> q;
    q.push(u);

    while (!q.empty()) {
      int v = q.front(); q.pop();
      if (color[v]) continue;
      color[v] = true;
      tree.pb(v);
      s_tree.insert(v);

      for (int w: graph_m[v]) {
        if (color[w]) continue;
        q.push(w);
      }
    }

    // for (int tmp: tree) {
    //   cout << tmp;
    // }
    // cout << endl;

    int size = tree.size();

    for (auto v: tree) {
      int block_cnt = 0;
      for(auto w: graph_k[v]) {
        if (Find(s_tree, w) ) {
          block_cnt++;
        }
      }
      ans[v] = (size - 1) - block_cnt - graph_m[v].size();
    }
  }

  rep(i, 0, ans.size()) {
    if (i < ans.size() - 1) {
      printf("%d ", ans[i]);
    } else {
      printf("%d\n", ans[i]);
    }
  }
};
