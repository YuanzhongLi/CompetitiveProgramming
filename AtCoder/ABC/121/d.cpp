#include <bits/stdc++.h>
using namespace std;

long long totalXorFrom0 (long long x) {
  long long ret = 0;
  if (x != 0) {
    if ((x % 2) == 0) {
      long long tmp = (x / 2);
      if ((tmp % 2) == 0) {
        ret = x;
      } else {
        ret = (x + 1);
      }
      return ret;
    } else {
      long long tmp = ((x / 2) + 1);
      if ((tmp % 2) == 0) {
        return 0;
      } else {
        return 1;
      }
    }
  } else {
    return 0;
  }
};

long long totalXor(long long A, long long B) {
  if (A == B) {
    return A;
  } else if (A == 0) {
    return totalXorFrom0(B);
  } else {
    return (totalXorFrom0(A - 1) ^ totalXorFrom0(B));
  }
};

int main() {
  long long A, B;
  cin >> A >> B;
  cout << totalXor(A, B) << endl;
};