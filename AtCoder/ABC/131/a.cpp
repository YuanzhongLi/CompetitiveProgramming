#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long

int main() {
  string s;
  cin >> s;
  if (s[0] == s[1] || s[1] == s[2] || s[2] == s[3]) {
    cout << "Bad" << endl;
  } else {
    cout << "Good" << endl;
  }
};
