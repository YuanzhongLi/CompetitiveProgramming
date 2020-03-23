#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j

int lbidx(vector<int> x, int y) {
  auto itr = lower_bound(x.begin(), x.end(), y);
  int idx = itr - x.begin();
  return idx;
};

int upidx(vector<int> x, int y) {
  auto itr = upper_bound(x.begin(), x.end(), y);
  int idx = itr - x.begin();
  return idx;
}

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  rep(i, 0, N) {
    cin >> H[i];
  }
  vector<vector<int>> block(100, vector<int> (100, 0));

  rep(i, 0, N) {
    int h = H[i];
    rep(j, 0, h) {
      block[j][i] = 1;
    }
  }
  int ans = 0;
  rep(i, 0, 100) {
    vector<int> row = block[i];
    rep(j, 0, row.size()) {
      int cell = row[j];
      if (j == 0) {
        if (cell == 1) {
          ans++;
        }
      } else {
        if (cell == 1 && row[j - 1] == 0) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
};
