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

int main() {
  string S;
  cin >> S;
  ll K;
  cin >> K;
  int n = S.size();
  if (S[n - 1] != S[0] || K == 1) {
    S.push_back('B');
    int pans = 0;
    char tmp ='A';
    int tmpn = 0;
    rep(i, 0, n+1) {
      char ch = S[i];
      if (tmp != ch) {
        pans += (tmpn / 2);
        tmpn = 1;
        tmp = ch;
      } else if (tmp == ch) {
        tmpn++;
      }
    }

    ll ans = pans * K;
    cout << ans << endl;
    return 0;
  } else {
    int sidx;
    int eidx;
    char jch = S[0];

    int sn = 0;
    int en = 0;

    for (int i = 0; i < n; i++) {
      if (S[i] != jch) {
        break;
      } else {
        sidx = i;
        sn++;
      }
    }

    for (int i = n - 1; i >= 0; i--) {
      if (S[i] != jch) {
        break;
      } else {
        eidx = i;
        en++;
      }
    }

    if (sidx == n - 1) {
      ll ans = (n * K) / 2;
      cout << ans << endl;
      return 0;
    }

    string S1 = string (S.begin(), S.begin() + eidx);
    string S2 = string (S.begin() + sn, S.end());
    string S3 = string (S.begin() + sn, S.begin() + eidx);

    S1.push_back('B');
    S2.push_back('B');
    S3.push_back('B');

    int pans1 = 0;
    int pans2 = 0;
    int pans3 = 0;
    char tmp1 ='A';
    char tmp2 ='A';
    char tmp3 ='A';
    int tmpn1 = 0;
    int tmpn2 = 0;
    int tmpn3 = 0;
    rep(i, 0, S1.size()) {
      char ch = S1[i];
      if (tmp1 != ch) {
        pans1 += (tmpn1 / 2);
        tmpn1 = 1;
        tmp1 = ch;
      } else if (tmp1 == ch) {
        tmpn1++;
      }
    }
    rep(i, 0, S2.size()) {
      char ch = S2[i];
      if (tmp2 != ch) {
        pans2 += (tmpn2 / 2);
        tmpn2 = 1;
        tmp2 = ch;
      } else if (tmp2 == ch) {
        tmpn2++;
      }
    }
    rep(i, 0, S3.size()) {
      char ch = S3[i];
      if (tmp3 != ch) {
        pans3 += (tmpn3 / 2);
        tmpn3 = 1;
        tmp3 = ch;
      } else if (tmp3 == ch) {
        tmpn3++;
      }
    }

    ll ans = pans1 + pans2 + (K - 2) * pans3 + (K - 1) * ((sn + en) / 2);
    cout << ans << endl;
  }
};
