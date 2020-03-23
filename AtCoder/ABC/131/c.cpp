#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long

int main() {
  ll A, B, C, D;
  cin >> A >> B >> C >> D;

  int gcd = __gcd(C, D);
  ll lcm = C * D / gcd;

  ll a = A - 1;

  ll r = B - (ll)(B / C) - (ll)(B / D) + (ll)(B / lcm);
  ll l = a - (ll)(a / C) - (ll)(a / D) + (ll)(a / lcm);

  ll ans = r - l;
  cout << ans << endl;
};
