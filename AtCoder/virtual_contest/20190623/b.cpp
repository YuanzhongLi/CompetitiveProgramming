#include <bits/stdc++.h>
using namespace std;

int A;
int B;

int dis(int d) {
  if (d < A) return A;
  if (d > B) return B;
  return d;
};

int main() {
  int N;
  cin >> N >> A >> B;

  vector<string> S(N);
  vector<int> D(N);

  for (int i = 0; i < N; i++) {
    cin >> S[i] >> D[i];
  }

  int x = 0;

  for (int i = 0; i < N; i++) {
    int d = dis(D[i]);
    if (S[i] == "East") {
      x += d;
    } else {
      x -= d;
    }
  }

  if (x == 0) {
    cout << x << endl;
  } else if (x > 0) {
    cout << "East " << abs(x) << endl;
  } else {
    cout << "West " << abs(x) << endl;
  }
};
