#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, Q;
  cin >> A >> B >> Q;
  vector<long long> s(A);
  vector<long long> t(B);
  vector<long long> x(Q);
  for (int i = 0; i < A; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < B; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < Q; i++) {
    cin >> x[i];
  }

  long long backOver = -(2e10 + 7);
  long long frontOver = (2e10 + 7);

  s.push_back(frontOver);
  s.insert(s.begin(), backOver);
  t.push_back(frontOver);
  t.insert(t.begin(), backOver);

  for (int i = 0; i < Q; i++){
    long long xi = x[i];

    auto iterS = lower_bound(s.begin(), s.end(), xi);
    auto iterT = lower_bound(t.begin(), t.end(), xi);

    long long frontClosestS = *(iterS - 1);
    long long backClosestS = *(iterS);
    long long frontClosestT = *(iterT - 1);
    long long backClosestT = *(iterT);

    long long diffFS = abs(frontClosestS - xi);
    long long diffBS = abs(backClosestS - xi);
    long long diffFT = abs(frontClosestT - xi);
    long long diffBT = abs(backClosestT - xi);

    long long costFSFT = max(diffFS, diffFT);
    long long costFSBT = (min(diffFS, diffBT) * 2 + max(diffFS, diffBT));
    long long costBSFT = (min(diffBS, diffFT) * 2 + max(diffBS, diffFT));
    long long costBSBT = max(diffBS, diffBT);

    vector<long long> cost = { costFSFT, costFSBT, costBSFT, costBSBT};

    sort(cost.begin(), cost.end());

    cout << cost[0] << endl;
  }
};
