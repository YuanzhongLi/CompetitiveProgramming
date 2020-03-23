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
static const int INF = 1e9+7;

int main() {
  int n;
  while(cin >> n, n) {
    vector<vector<int>> dist(11, vector<int> (11, INF));
    int v = 0;
    int a, b, c;

    rep(i, 0, n) {
      cin >> a >> b >> c;
      dist[a][b] = c;
      dist[b][a] = c;
      dist[a][a] = 0;
      dist[b][b] = 0;
      v = max(v, a+1);
      v = max(v, b+1);
    }

    rep(i, 0, v) {
      dist[i][i] = 0;
    }

    rep(k, 0, v) {
      rep(i, 0, v) {
        rep(j, 0, v) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }

    int cost = INF;
    int town;
    rep(i, 0, v) {
      int c = 0;
      rep(j, 0, v) {
        c += dist[i][j];
      }

      if (c < cost) {
        cost = c;
        town = i;
      }
    }

    cout << town << ' ' << cost << endl;
  }

  return 0;
};
