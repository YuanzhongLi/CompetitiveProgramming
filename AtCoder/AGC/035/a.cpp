#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define BiSearchRangeNum(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y)

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  set<int> S;
  rep(i, 0, N) {
    cin >> A[i];
    S.insert(A[i]);
  }
  if (S.size() == 3 && A.size() % 3 == 0) {
    int a, b, c;
    a = *(S.begin());
    S.erase(a);
    b = *(S.begin());
    S.erase(b);
    c = *(S.begin());
    S.erase(c);
    int cnta, cntb, cntc;
    cnta = cntb = cntc = 0;
    rep(i, 0, N) {
      if (A[i] == a) cnta++;
      if (A[i] == b) cntb++;
      if (A[i] == c) cntc++;
    }
    if (int(a ^ b) == c && cnta == cntb && cntb == cntc) {
      cout << "Yes" << endl;
    } else cout << "No" << endl;
  } else if (S.size() == 2 && A.size() % 3 == 0) {
    int a, b;
    a = *(S.begin());
    S.erase(a);
    b = *(S.begin());
    S.erase(b);
    int cnta, cntb;
    cnta = cntb = 0;
    if (int(a ^ b) == b) {
      rep(i, 0, N) {
        if (A[i] == a) cnta++;
        if (A[i] == b) cntb++;
      }
      if (cntb == cnta * 2) {
        cout << "Yes" << endl;
      } else cout << "No" << endl;
    } else if (int(a ^ b) == a) {
      rep(i, 0, N) {
        if (A[i] == a) cnta++;
        if (A[i] == b) cntb++;
      }
      if (cnta == 2 * cntb) {
        cout << "Yes" << endl;
      } else cout << "No" << endl;
    } else cout << "No" << endl;
  } else if (S.size() == 1) {
    int a = *(S.begin());
    if (a == 0) {
      cout << "Yes" << endl;
    } else cout << "No" << endl;
  } else {
    cout << "No" << endl;
  }
};
