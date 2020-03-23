#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long

int main() {
  int N;
  cin >> N;
  vector<pair<ll, ll>> AB(N);
  rep(i, 0 , N) {
    cin >> AB[i].second >> AB[i].first;
  }
  sort(AB.begin(), AB.end());
  ll cntA = 0;
  ll deadline = 0;
  bool success = true;
  rep(i, 0, N) {
    cntA += AB[i].second;
    deadline = AB[i].first;
    if (cntA > deadline) {
      success = false;
      break;
    }
  }
  if (success) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
};
