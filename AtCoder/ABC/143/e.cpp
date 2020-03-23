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


static const int MAX = 400;
static const ll INFTY = 1e15;

ll N, M, L, Q;
ll fuel[MAX][MAX];
ll dist[MAX][MAX];
ll s[105000], t[105000];
ll A[100000], B[100000], C[100000];

void input() {
  cin >> N >> M >> L;
  for (int i = 1; i <= M; i++) cin >> A[i] >> B[i] >> C[i];
  cin >> Q;
  for (int i = 1; i <= Q; i++) cin >> s[i] >> t[i];
}

void solve() {
  input();
  // 初期化
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      fuel[i][j] = INFTY;
      dist[i][j] = INFTY;
    }
    fuel[i][i] = 0;
    dist[i][i] = 0;
  }

  // 初期node間距離代入
  for (int i = 1; i <= M; i++) {
    chmin(fuel[A[i]][B[i]], C[i]);
    chmin(fuel[B[i]][A[i]], C[i]);
  }

  // フロイド法によって全点間の最短距離を算出
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      for (int k = 1; k <= N; k++) {
        chmin(fuel[j][k], fuel[j][i] + fuel[i][k]);
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i == j) continue;
      // 距離がL以下(つまり進める)の場合, 距離を1とする
      if (fuel[i][j] <= L) chmin(dist[i][j], 1LL);
    }
  }

  // 上のようにL以下の距離を1として処理した後, フロイド方を行う
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      for (int k = 1; k <= N; k++) {
        chmin(dist[j][k], dist[j][i] + dist[i][k]);
      }
    }
  }

  for (int i = 1; i <= Q; i++) {
    if (dist[t[i]][s[i]] < INFTY) cout << dist[t[i]][s[i]] - 1 << endl;
    else cout << -1 << endl;
  }
  return;
};

int main() {
  solve();
  return 0;
};
