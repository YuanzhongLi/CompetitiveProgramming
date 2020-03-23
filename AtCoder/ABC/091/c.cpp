#include <bits/stdc++.h>
using namespace std;

bool sortx(pair<int, int> first, pair<int, int> second) {
  return first.first > second.first;
};

bool sorty(pair<int, int> first, pair<int, int> second) {
  return first.second < second.second;
};

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> red(N);
  vector<pair<int, int>> blue(N);

  for (int i = 0; i < N; i++) {
    cin >> red[i].first >> red[i].second;
  }
  sort(red.begin(), red.end(), sortx);

  for (int i = 0; i < N; i++) {
    cin >> blue[i].first >> blue[i].second;
  }
  sort(blue.begin(), blue.end(), sorty);

  int pairs = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < red.size(); j++) {
      if ((blue[i].first > red[j].first) && (blue[i].second > red[j].second)) {
        pairs += 1;
        red.erase(red.begin() + j);
        break;
      }
    }
  }
  cout << pairs << endl;
};
