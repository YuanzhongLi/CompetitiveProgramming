#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j

int main() {
  int N, A, B, C, D;
  string S;
  cin >> N >> A >> B >> C >> D;
  A--; B--; C--; D--;
  cin >> S;
  vector<int> vecS(N);
  rep(i, 0, N) {
    char ch = S[i];
    if (ch == '.') {
      vecS[i] = 0;
    } else vecS[i] = 1;
  }

  if (C < D) {
    bool flag = true;
    rep(i, A, D) {
      if (vecS[i] == 1 && vecS[i + 1] == 1) {
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
    return 0;
  } else {
    bool flag1 = true;

    rep(i, A, C) {
      if (vecS[i] == 1 && vecS[i + 1] == 1) {
        flag1 = false;
        break;
      }
    }
    if (!flag1) {
      cout << "No" << endl;
      return 0;
    }

    bool flag = false;
    rep(i, B, D + 1) {
      if (vecS[i - 1] == 0 && vecS[i] == 0 && vecS[i + 1] == 0) {
        flag = true;
        break;
      }
    }
    if (flag) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
    return 0;
  }
};
