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

int main() {
    int N;
    cin >> N;
    ll K;
    cin >> K;
    vector<ll> A(N);
    vector<ll> F(N);
    rep(i, 0, N) {
        cin >> A[i];
    }
    rep(i, 0, N) {
        cin >> F[i];
    }
    sort(All(A));
    sort(All(F));
    reverse(All(F));

    ll ok = 1e12;
    ll ng = -1;

    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        ll cnt = 0;
        rep(i, 0, N) {
            if (A[i] * F[i] <= mid) continue;
            else {
                cnt += A[i] - mid / F[i];
            }
        }
        if (cnt <= K) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    cout << ok << endl;
};
