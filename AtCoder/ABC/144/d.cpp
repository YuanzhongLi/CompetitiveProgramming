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
    double a, b, x;
    cin >> a >> b >> x;
    double ar1 = b * a;
    double ar2 = x / a;
    if (ar2 * 2 >= ar1) {
        double ta = ar1 - ar2;
        double y = 2 * ta / a;
        double ans = (atan2(y, a) / 2/ M_PI) * (double) 360;
        printf("%.10f\n", ans);
        return 0;
    } else {
        double y = ar2 * (double) 2 / b;
        double ans = (atan2(b, y) / 2/ M_PI) * (double) 360;
        printf("%.10f\n", ans);
        return 0;
    }
};
