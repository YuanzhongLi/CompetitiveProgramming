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

pair<int, char> to_score(char ch, int R, int S, int P) {
  int ret = 0;
  char retch;
  if (ch == 'r') {
    ret = P;
    retch = 'p';
  } else if (ch == 's') {
    ret = R;
    retch = 'r';
  } else {
    ret = S;
    retch = 's';
  }
  return make_pair(ret, retch);
};

pair<int, char> to_s(char ch, char ch2, char ch3, int R, int S, int P) {
  int ret = 0;
  char retch = 'q';
  if (ch == 'r') {
    if (ch2 == 'p' || ch3 == 'p'  || ch2 == 'q') {
      ret = P;
      retch = 'p';
    }
  } else if (ch == 's') {
    if (ch2 == 'r' || ch3 == 'r'  || ch2 == 'q') {
      ret = R;
      retch = 'r';
    }
  } else if (ch == 'p') {
    if (ch2 == 's' || ch3 == 's' || ch2 == 'q') {
      ret = S;
      retch = 's';
    }
  }
  return make_pair(ret, retch);
};

int main() {
  int N, K, R, S, P;
  cin >> N >> K >> R >> S >> P;
  string T;
  cin >> T;

  int ans = 0;
  vector<char> memo(N);

  rep(i, 0, K) {
    char ch = T[i];
    auto tmp = to_score(ch, R, S, P);
    ans += tmp.first;
    memo[i] = tmp.second;
  }

  rep(i, K, T.size()) {
    char ch = T[i];
    char ch2, ch3;
    char ch4 = memo[i - K];
    if (ch4 == 'r') {
      ch2 = 's';
      ch3 = 'p';
    } else if (ch4 == 's') {
      ch2 = 'p';
      ch3 = 'r';
    } else if (ch4 == 'p') {
      ch2 = 'r';
      ch3 = 's';
    } else if (ch4 == 'q') {
      ch2 = ch3 = 'q';
    }

    auto tmp = to_s(ch, ch2, ch3, R, S, P);
    ans += tmp.first;
    memo[i] = tmp.second;
  }

  cout << ans << endl;
};
