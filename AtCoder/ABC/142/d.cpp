#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define BiSearchRangeNum(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y)

vector<ll> divisor(ll n) {
  vector<ll> ret;
  for(int i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.pb(i);
      if(i * i != n) ret.pb(n / i);
    }
  }
  sort(All(ret));
  return (ret);
}

int divisorNum(ll n) {
  vector<ll> ret;
  for(int i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.pb(i);
      if(i * i != n) ret.pb(n / i);
    }
  }
  return (ret.size());
}

set<ll> S;

void decompositPrime(ll n)
{
    // 割る数の初期値
    ll a = 2;
    // √n ≧ a ( n ≧ a * a ) の間ループ処理
    while (n >= a * a) {
        // a で割り切れたら、a は素因数
        // そして、割られる数を a で割る
        // a で割り切れなかったら、 a を 1 増加させる
        if (n % a == 0) {
            S.insert(a);
            n /= a;
        } else {
            a++;
        }
    }
    // 最後に残った n は素因数
    S.insert(n);
}


int main() {
  ll A, B;
  cin >> A >> B;
  ll gcd = __gcd(A, B);
  S.insert(1);

  decompositPrime(gcd);

  cout << S.size() << endl;

};
