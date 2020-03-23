#include <bits/stdc++.h>
using namespace std;

void mr(vector<int> i, vector<int> &g) {
  for
  if (i != g.size() - 1) {
    g[i + 1] += g[i];
  }
  g[i] = 0;
};

void ml(int i, vector<int> &g) {
  if (i != 0) {
    g[i - 1] += g[i];
  }
  g[i] = 0;
};

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> g(N, 1);

  vector<vector<int>> array;
  for (int i = 0; i < N; i++) {
    int in;
    cin >> in;
    array[in].push_back(i);
  }

  for (int i = 0; i < Q; i++) {
    int in;
    cin >> in;
    char order;
    cin >> order;
    if (order == 'R') {
      array
    }
    if (order == 'L') {
      ml(i, g);
    }
  }

};
