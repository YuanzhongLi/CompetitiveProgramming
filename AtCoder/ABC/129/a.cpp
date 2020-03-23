#include <bits/stdc++.h>
using namespace std;

int main() {
  int p, q, r;
  cin >> p >> q >> r;
  int pq = p+q;
  int qr = q+r;
  int pr = p+r;
  cout << min(pq, min(qr, pr)) << endl;
};
