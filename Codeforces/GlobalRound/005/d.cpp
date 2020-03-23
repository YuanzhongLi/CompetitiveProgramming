#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define eb emplace_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define llbidx(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y) // 二要素間の距離
#define deg2rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad2deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)
#define Find(set, element) set.find(element) != set.end()
#define Decimal(x) printf("%.10f\n", x) // 小数点を10桁まで表示
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;

int POWINT(int x, int n) {
  int ret = 1;
  rep(i, 0, n) ret *= x;
  return ret;
};

ll POWLL(int x, int n) {
  ll ret = 1;
  rep(i, 0, n) ret *= x;
  return ret;
};

template<class T>
inline bool chmax(T &a, T b) {
  if(a < b) {
    a = b;
    return true;
  }
  return false;
};

template<class T>
inline bool chmin(T &a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
};

const int INF = 1e9+7;

int main() {
  int n;
  cin >> n;
  vector<int> inp(n);

  int ma = 0;
  int mi = INF;

  rep(i, 0, n) {
    cin >> inp[i];
    ma = max(ma, inp[i]);
    mi = min(mi, inp[i]);
  }

  if (ma <= mi*2) {
    rep(i, 0, n) {
      if (i != 0) {
        cout << " ";
      }
      cout << - 1;
    }
    cout << endl;
    return 0;
  }

  vector<int> a(3*n);
  rep(i, 0, n) {
    a[i] = a[i+n] = a[i+n*2] = inp[i];
  }

  vector<int> st_max;
  vector<int> st_min;

  vector<int> ans(3 * n);

  for (int i = 3*n - 1; i >= 0; i--) {
    while (!st_max.empty() && a[st_max.back()] < a[i]) {
      st_max.pop_back();
    }

    while (!st_min.empty() && a[st_min.back()] > a[i]) {
      st_min.pop_back();
    }

    int low = 0, high = (int) st_min.size();
    while (abs(high - low) > 1) {
      int mid = (low + high) >> 1;
      if (a[st_min[mid]] * 2 < a[i]) {
        low = mid;
      } else {
        high = mid;
      }
    }

    int nxt = 3 * n;

    if (!st_min.empty()) {
      nxt = min(nxt, st_min[low]);
    }

    if (!st_max.empty()) {
      nxt = min(nxt, st_max.back());
    }

    if (nxt < 3 * n && a[nxt] >= a[i]) {
      ans[i] = ans[nxt];
    } else {
      ans[i] = nxt;
    }

    st_min.pb(i);
    st_max.pb(i);
  }

  rep(i, 0, n) {
    if (i > 0) {
      cout << " ";
    }
    cout << (ans[i] - i);
  }
  cout << endl;

  return 0;
};
