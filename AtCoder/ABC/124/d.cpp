#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    int tmp = 0;
    vector<int> leng;
    vector<int> gain;

    // enumerating switching points
    leng.push_back(0);
    for(int i = 1; i < S.length(); i++){
        if(S[i] != S[i-1]) leng.push_back(i);
    }

    // calculating gain depending on each element of leng
    for(int i = 0; i < leng.size(); i++){
        if(S[leng[i]] == '0') tmp = 2*K;
        else tmp = 2*K + 1;

        if(i+tmp >= leng.size()) gain.push_back(N-leng[i]);
        else gain.push_back(leng[i+tmp]-leng[i]);
    }

    cout << *max_element(gain.begin(), gain.end()) << '\n';

    return 0;
};
