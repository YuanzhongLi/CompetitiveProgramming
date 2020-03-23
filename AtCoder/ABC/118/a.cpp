#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long

int main() {
  int A, B;
  cin >> A >> B;
  if (B % A == 0) cout << A + B << endl;
  else cout << B - A << endl;
};
