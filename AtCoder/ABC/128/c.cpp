#include <bits/stdc++.h>
using namespace std;

// 左づめでの10進数xをdigits桁のN進数vectorにしてを返す
vector<int> baseNumber(int N, int digits, int x) {
  vector<int> ret(digits, 0);
  // 商
  int quotient = x;
  int counter = 0;
  while (quotient > 0) {
    // 余り
    int remainder = quotient % N;
    quotient /= N;
    ret[counter] = remainder;
    counter++;
  }

  return ret;
};

// n-1までのN進数を上記のbaseNumberで返したvectorのvector
vector<vector<int>> baseNumbers(int n, int N, int digits) {
  vector<vector<int>> ret(n, vector<int> (digits));
  for (int i = 0; i < n; i++) {
    ret[i] = baseNumber(N, digits, i);
  }

  return ret;
};


int main() {
  int n, m;
  cin >> n >> m;

  vector<int> k(m);
  vector<vector<int>> s(m, vector<int> (10));
  vector<int> p(m);

  for (int i = 0; i < m; i++) {
    cin >> k[i];
    for (int j = 0; j < k[i]; j++) {
      cin >> s[i][j];
    }
  }

  for (int i = 0; i < m; i++) {
    cin >> p[i];
  }

  vector<vector<int>> dfs = baseNumbers((int)pow(2, n), 2, n);

  int ans = 0;
  for (int i = 0; i < dfs.size(); i++) {
    vector<int> bn = dfs[i];
    bool flag = true;
    for (int j = 0; j < m; j++) {
      int ons = 0;
      for (int l = 0; l < k[j]; l++) {
        if (bn[s[j][l] - 1] == 1) ons++;
      }
      if (!(ons % 2 == p[j])) {
        flag = false;
        break;
      }
    }
    if (flag) ans++;
  }

  cout << ans << endl;
};
