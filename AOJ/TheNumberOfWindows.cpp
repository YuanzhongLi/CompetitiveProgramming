#include <bits/stdc++.h>
using namespace std;

int N;

long long twoPointers (vector<int> a, long long x) {
  int r = 0;
  long long sum = 0;
  long long ans = 0;

  for (int l = 0; l < N; l++) {
    while (sum <= x) {
      if (r == N) {
        break;
      } else {
        if (sum + a[r] > x) {
          break;
        }
        sum += a[r];
        r++;
      }
    }
    ans += r - l;
    sum -= a[l];
  }
  return ans;
};

int main() {
  int Q;
  cin >> N >> Q;
  vector<int> a(N);
  vector<long long> x(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < Q; i++) {
    cin >> x[i];
  }

  for (int i = 0; i < Q; i++) {
    long long ans = twoPointers(a, x[i]);
    cout << ans << endl;
  }
};
