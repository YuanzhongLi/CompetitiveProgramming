#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N;
  vector<string> s(N);
  for (int i = 0; i < N; i++) {
    cin >> s[i];
  }
  cin >> M;
  vector<string> t(M);
  for (int i = 0; i < M; i++) {
    cin >> t[i];
  }

  vector<int> pointList(N);

  for (int i = 0; i < N; i++) {
    int point = 0;
    for (int j = 0; j < N; j++) {
      if (s[i] == s[j]) {
        point += 1;
      }
    }
    for(int k = 0; k < M; k++) {
      if(s[i] == t[k]) {
        point -= 1;
      }
    }
    if (point < 0) {
      point = 0;
    }
    pointList[i] = point;
  }

  sort(pointList.begin(), pointList.end());
  reverse(pointList.begin(), pointList.end());
  cout << pointList[0] << endl;
};
