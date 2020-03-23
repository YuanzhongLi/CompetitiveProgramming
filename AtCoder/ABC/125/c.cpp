#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<int> front(N - 1), back(N - 1);
  int gcdf = A[0];
  for (int i = 0; i < front.size(); i++) {
    gcdf = __gcd(gcdf, A[i]);
    front[i] = gcdf;
  }

  reverse(A.begin(), A.end());

  int gcdb = A[0];
  for (int i = 0; i < back.size(); i++) {
    gcdb = __gcd(gcdb, A[i]);
    back[i] = gcdb;
  }

  reverse(back.begin(), back.end());

  vector<int> gcd(N);
  for (int i = 0; i < N; i++) {
    if (i == 0) {
      gcd[i] = back[0];
    } else if (i == N - 1) {
      gcd[i] = front[front.size() - 1];
    } else {
      gcd[i] = __gcd(front[i - 1], back[i]);
    }

    // cout << gcd[i] << endl;
  }

  sort(gcd.begin(), gcd.end());
  reverse(gcd.begin(), gcd.end());
  cout << gcd[0] << endl;
};
