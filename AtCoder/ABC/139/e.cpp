#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define BiSearchRangeNum(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y)turn idx;
#define deg_to_rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad_to_deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)

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

typedef pair<int, int> P;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int> (n-1));
  rep(i, 0, n) {
    rep(j, 0, n-1) {
      cin >> a[i][j];
      a[i][j]--; // 選手番号を0スタートに調整
    }

    reverse(All(a[i])); // 先頭の削除が遅いので逆順にしとく
  }

  vector<P> q; // que

  // main関数内でも関数定義できる
  auto check = [&](int i) { // 選手iが試合できるかをcheckしてできる場合queに入れる
    if (a[i].size() == 0) return; // 対戦できない
    int j = a[i].back(); // vectorの末尾の要素を取得（iの次の対戦相手

    if (a[j].size() == 0) return; // 相手jと対戦できない
    if (a[j].back() == i) { // 対戦相手jの次の対戦相手が自分（i）の場合
      P p(i, j);
      // 重複をなくす（p.firstの方が小さいようにする）後の(1)より
      if (p.second < p.first) swap(p.first, p.second);
      q.pb(p);
    }
  };

  rep(i, 0, n) {
    check(i);
  }

  int day = 0;
  while (q.size() > 0) {
    day++;
    sort(All(q));
    q.erase(unique(All(q)), q.end()); // 重複を削除(1)
    vector<P> prevQ;
    swap(prevQ, q); // vectorのswapは高速（定数計算量とみることができる）
    for (P p: prevQ) { // 試合を消化
      int i = p.first, j = p.second;
      a[i].pop_back();
      a[j].pop_back();
    }
    for (P p: prevQ) { // 試合を消化した後に次にできる試合をcheck
      int i = p.first, j = p.second;
      check(i);
      check(j);
    }

    // prevQ, qは高々試合数O(N^2)しかない!
  }

  rep(i, 0, n) {
    if (a[i].size() != 0) {
      cout << -1 << endl;
      return 0;
    }
  }

  cout << day << endl;
  return 0;
};
