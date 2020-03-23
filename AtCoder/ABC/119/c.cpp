#include <bits/stdc++.h>
using namespace std;

enum treeNums { Not, ANum, BNum, CNum};

int main() {
  int N, A, B, C;
  cin >> N >> A >> B >> C;
  vector<int> ls(N);
  for (int i = 0; i < N; i++) {
    cin >> ls[i];
  }

  int depth = pow(4, N);

  vector<vector<int>> base4_Array(pow(4, N), vector<int>(N));

  for (int i = 0; i < depth; i++) {
    int remainder = i;
    for(int j = 0; j < N; j++) {
      int quotient = (remainder / (pow(4, (N - 1) - j)));
      remainder %= (int)pow(4, (N - 1) - j);
      base4_Array[i][j] = quotient;
    }
  }

  vector<int> costList(depth);
  for (int i = 0; i < depth; i++) {
    int cost = 0;
    int connectLengthA = 0;
    int connectLengthB = 0;
    int connectLengthC = 0;
    for (int j = 0; j < N; j++) {
      int base4 = base4_Array[i][j];
      if (base4 == ANum) {
        connectLengthA += ls[j];
        cost += 10;
      } else if (base4 == BNum) {
        connectLengthB += ls[j];
        cost += 10;
      } else if (base4 == CNum) {
        connectLengthC += ls[j];
        cost += 10;
      }
    }
    if ((connectLengthA != 0) && (connectLengthB != 0) && (connectLengthC != 0)) {
      cost += (abs(connectLengthA - A) + abs(connectLengthB - B) + abs(connectLengthC - C) - 30);
    } else {
      cost = 1e9;
    }
    costList[i] = cost;
  }

  sort(costList.begin(), costList.end());
  cout << costList[0] << endl;
};
