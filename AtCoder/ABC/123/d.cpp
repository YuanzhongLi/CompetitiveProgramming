#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y, Z, K;
  cin >> X >> Y >> Z >> K;
  vector<long long> A(X);
  vector<long long> B(Y);
  vector<long long> C(Z);
  for (int i = 0; i < X; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < Y; i++) {
    cin >> B[i];
  }
  for (int i = 0; i < Z; i++) {
    cin >> C[i];
  }

  vector<long long> AB(X * Y);
  int index = 0;
  for (int i = 0; i < X; i++) {
    for (int j = 0; j < Y; j++) {
      AB[index] = A[i] + B[j];
      index += 1;
    }
  }

  sort(AB.begin(), AB.end());
  reverse(AB.begin(), AB.end());

  vector<long long> V(min(K, X * Y));
  for (int i = 0; i < min(K, X * Y); i++) {
    V[i] = AB[i];
  }

  index = 0;

  vector<long long> abc(V.size() * Z);
  for (int i = 0; i < Z; i++) {
    for (int j = 0; j < V.size(); j++) {
      abc[index] = C[i] + V[j];
      index += 1;
    }
  }

  sort(abc.begin(), abc.end());
  reverse(abc.begin(), abc.end());

  vector<long long> ans(K);
  for (int i = 0; i < K; i++) {
    ans[i] = abc[i];
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
};
