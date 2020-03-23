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

class Work {
  public:
  int day, reward;
  Work(int day = 0, int reward = 0): day(day), reward(reward) {}
  bool operator < (const Work &w) const {
    return reward < w.reward;
  }
};

int main() {
  int N, M;
  cin >> N >> M;
  int A, B;
  priority_queue<Work> pq;
  map<int, vector<Work>> m;
  rep(i, 0, N) {
    cin >> A >> B;
    Work w = Work(A, B);
    m[A].pb(w);
  }

  vector<Work> ans(M+1);

  rep(i, 1, M+1) {
    if (m.count(i) > 0) {
      for (auto it = m[i].begin(); it != m[i].end(); it++) {
        // cout << i << "日, day: " << it->day << ", reward: " << it->reward << endl;
        pq.push(*it);
      }
    }
    Work w;
    if (!pq.empty()) {
      w = pq.top(); pq.pop();
    }
    ans[i] = w;
  }

  int total = 0;

  rep(i, 1, M+1) {
    total += ans[i].reward;
  }

  cout << total << endl;
};
