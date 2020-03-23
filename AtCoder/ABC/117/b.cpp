#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j

int main() {
  int N;
  cin >> N;
  vector<int> L(N);
  rep(i, 0, N) {
    cin >> L[i];
  }
  sort(All(L));
  int biggest = L[N - 1];
  int tmp = 0;
  rep(i, 0, N - 1) {
    tmp += L[i];
  }
  if (biggest < tmp) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
};
