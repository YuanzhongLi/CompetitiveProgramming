#include <bits/stdc++.h>
using namespace std;

int main() {
  char b;
  cin >> b;
  if (b == 'A') b = 'T';
  else if (b == 'T') b = 'A';
  else if (b == 'C') b = 'G';
  else b = 'C';
  printf("%c\n", b);
};
