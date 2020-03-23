#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N, K;
  cin >> N >> K;
  double ans = 0;

  if (K == 1) {
    cout << (double)1 << endl;
    return 0;
  }

  if (N >= K) {
    ans += (N - K + 1);
  }

  int tmp = K;
  int tmp2 = 1;
  int a[K + 1];
  while (tmp > 1) {
    int start;
    int end = tmp - 1;
    if (tmp % 2 == 0) start = tmp / 2;
    else start = tmp / 2 + 1;
    for (int i = start; i <= end; i++) {
      a[i] = tmp2;
    }
    tmp = start;
    tmp2++;
  }

  for (int i = 1; i <= min(N, K - 1); i++) {
    ans += pow(0.5, a[i]);
  }

  ans = ans / N;

  printf("%.10f\n", ans);

};
