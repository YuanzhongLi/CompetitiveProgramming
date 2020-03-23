#include <bits/stdc++.h>
using namespace std;

int main() {
  int txa, tya, txb, tyb, T, V, n;
  cin >> txa >> tya >> txb >> tyb >> T >> V >> n;
  vector<pair<int, int>> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i].first >> vec[i].second;
  }

  int MAX = T * V;

  bool ans = false;
  for (int i = 0; i < n; i++) {
    double dis1, dis2;
    dis1 = pow(pow(abs(vec[i].first - txa), 2) + pow(abs(vec[i].second - tya), 2), 0.5);
    dis2 = pow(pow(abs(vec[i].first - txb), 2) + pow(abs(vec[i].second - tyb), 2), 0.5);
    if (MAX >= dis1 + dis2 - 0.001) {
      ans = true;
      break;
    }
  }

  if (ans) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
};
