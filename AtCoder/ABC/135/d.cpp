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

static const int mod = 1e9+7;

ll dp[100001][13];


int main() {
  string S;
  cin >> S;
  reverse(All(S));
  dp[0][0] = 1;

  ll b = 1;
  int size = S.size();
  rep(i, 0, size) {
    // 桁
    int idx = i+1;
    char ch = S[i];
    int s = S[i];
    s -= 48;
    if (ch != '?') {
      // 桁の数によるmod
      int digitmod = s * b % 13;
      rep(j, 0, 13) {
        // 一つ前の個数 j mod 13 での個数
        int prev = dp[i][j];
        // 一つ前と合計した時のmod
        int tmpmod = (digitmod + j) % 13;
        dp[idx][tmpmod] += prev;
        dp[idx][tmpmod] %= mod;
      }
    } else {
      rep(j, 0, 13) {
        // 一つ前の j mod 13 での個数
        int prev = dp[i][j];
        rep(k, 0, 10) {
          // 桁の数によるmod
          int digitmod = k * b % 13;
          // 一つ前と合計した時のmod
          int tmpmod = (digitmod + j) % 13;
          dp[idx][tmpmod] += prev;
          dp[idx][tmpmod] %= mod;
        }
      }
    }
    b *= 10;
    b %= 13;
  }

  cout << dp[size][5] << endl;
};
