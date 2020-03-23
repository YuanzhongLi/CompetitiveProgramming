#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j

// 左づめでの10進数xをdigits桁のN進数vectorにしてを返す
vector<int> baseNumber(int N, int digits, ll x) {
  vector<int> ret(digits, 0);
  // 商
  ll quotient = x;
  int counter = 0;
  while (quotient > 0) {
    // 余り
    int remainder = quotient % N;
    quotient /= N;
    ret[counter] = remainder;
    counter++;
  }

  return ret;
};

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  vector<int> BiA[N];
  // Aにおいて桁数に0, 1が何個存在するか
  vector<int> digit0num(40, 0);
  vector<int> digit1num(40, 0);
  rep(i, 0, N) {
    cin >> A[i];
    BiA[i] = baseNumber(2, 40, A[i]);
    rep(j, 0, 40) {
      int tmp = BiA[i][j];
      if (tmp == 1) {
        digit1num[j]++;
      } else {
        digit0num[j]++;
      }
    }
  }

  vector<int> BiK = baseNumber(2, 40, K + 1);
  vector<ll> ans;
  rep(i, 0, 40) {
    ll ansi = 0;
    int Ki = BiK[i];
    if (Ki == 0) continue;
    rep(j, 0, 40) {
      if (j == i) {
        ansi += (1ll<<j) * digit1num[j];
      } else if (j < i) {
        ansi += (1ll<<j) * max(digit0num[j], digit1num[j]);
      } else {
        if (BiK[j] == 1) {
          ansi += (1ll<<j) * digit0num[j];
        } else {
          ansi += (1ll<<j) * digit1num[j];
        }
      }
    }
    ans.pb(ansi);
  }
  sort(All(ans));
  reverse(All(ans));
  cout << ans[0] << endl;
};
