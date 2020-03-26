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

int main() {
    int N;
    cin >> N;
    ll a, b, n, S;
    rep(i, 0, N) {
        cin >> a >> b >> n >> S;
        if (a * n >= S) {
            ll remain = S % n;
            if (remain <= b) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        } else {
            if (S - a * n <= b) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }

    return 0;
};
