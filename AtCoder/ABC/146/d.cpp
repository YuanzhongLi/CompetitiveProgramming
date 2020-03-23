#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define BiSearchRangeNum(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y)turn idx;
#define deg_to_rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad_to_deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)

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

static const int MAX = 100001;

vector<int> adj[MAX];
vector<int> used(MAX, 0);
int par[MAX];
map<pair<int, int>, int> c_map;

int bfs() {
  int ret = 0;

  queue<int> q;
  used[1] = 1;
  q.push(1);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    used[u] = 2;
    int c_num;
    if (u == 1) {
      c_num = 0;
    } else {
      c_num = 1;
    }

    rep(i, 0, adj[u].size()) {
      int v = adj[u][i];
      if (used[v] == 0) {
        used[v] = 1;
        q.push(v);
        c_num += 1;
      }
    }
    ret = max(ret, c_num);
  }

  return ret;
};

void solve(int m_c) {
  rep(i, 0, used.size()) {
    used[i] = 0;
  }

  par[1] = 0;
  queue<int> q;
  used[1] = 1;
  q.push(1);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    used[u] = 2;
    int p = par[u];
    int p_c;

    if (p == 0) {
      p_c = 0;
    } else {
      p_c = c_map[make_pair(p, u)];
    }

    int c = p_c;

    rep(i, 0, adj[u].size()) {
      int v = adj[u][i];

      if (used[v] == 0) {
        used[v] = 1;
        par[v] = u;
        q.push(v);
        if (c == m_c) {
          c = 1;
          c_map[make_pair(u, v)] = c;
          c_map[make_pair(v, u)] = c;
        } else {
          c+=1;
          c_map[make_pair(u, v)] = c;
          c_map[make_pair(v, u)] = c;
        }
      }
    }
  }
};

int main() {
  int N;
  cin >> N;
  int a, b;
  vector<pair<int, int>> input_edges(N - 1);
  rep(i, 0, N - 1) {
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
    input_edges[i].first = a;
    input_edges[i].second = b;
  }

  int max_color = bfs();

  cout << max_color << endl;
  solve(max_color);
  rep(i, 0, input_edges.size()) {
    cout << c_map[input_edges[i]] << endl;
  }
};
