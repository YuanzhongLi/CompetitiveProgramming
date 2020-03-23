#include <bits/stdc++.h>
using namespace std;
static const int null = -1;

int main() {
  int h, w;
  cin >> h >> w;
  int mat[h][w];
  vector<vector<int>> vech(h);
  vector<vector<int>> vecw(w);

  for (int i = 0; i < h; i++) {
    string S;
    cin >> S;
    for (int j = 0; j < w; j++) {
      char c = S[j];
      if (c == '#') {
        mat[i][j] = -1;
        vech[i].push_back(j);
        vecw[j].push_back(i);
      }
      else mat[i][j] = 1;
    }
  }

  vector<int> hw;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (mat[i][j] == -1) continue;

      int ansh, answ;
      auto hv = vech[i];
      auto wv = vecw[j];

      if (hv.empty()) {
        ansh = w - 1;
      } else {
        if (hv[hv.size() - 1] <= j) {
          ansh = w - 2 - hv[hv.size() - 1];
        } else {
          auto itr = upper_bound(hv.begin(), hv.end(), j);
          int index = distance(hv.begin(), itr);
          if (index == 0) {
            ansh = (*itr) - 1;
          } else {
            ansh = *itr - *(itr - 1) - 2;
          }
        }
      }

      if (wv.empty()) {
        answ = h - 1;
      } else {
        if (wv[wv.size() - 1] <= i) {
          answ = h - 2 - wv[wv.size() - 1];
        } else {
          auto itr = upper_bound(wv.begin(), wv.end(), i);
          int index = distance(wv.begin(), itr);
          if (index == 0) {
            answ = (*itr) - 1;
          } else {
            answ = *itr - *(itr - 1) - 2;
          }
        }
      }
      hw.push_back(ansh + answ + 1);
    }
  }

  // for (int i = 0; i < hw.size(); i++) {
  //   cout << hw[i] << endl;
  // }

  sort(hw.begin(), hw.end());
  reverse(hw.begin(), hw.end());
  cout << hw[0] << endl;
};
