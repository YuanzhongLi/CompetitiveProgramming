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

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
};

// a^n mod を計算する
long long modpow(long long a, long long n, long long m) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return res;
};

static ll mod = 998244353;

int main() {
    int N;
    cin >> N;
    vector<int> tree(N);
    rep(i, 0, N) {
        cin >> tree[i];
    }
    if (tree[0] != 0) {
        cout << 0 << endl;
        return 0;
    }

    sort(All(tree));

    if (tree.size() > 1) {
        if (tree[1] != 1) {
            cout << 0 << endl;
            return 0;
        }
    }

    int prev_total = 1;
    int total = 0;
    ll ans = 1;

    bool flag = true;

    tree.pb(-1);
    rep(i, 1, N) {
        int cur = tree[i];
        int next = tree[i+1];
        if (next - 1 > cur) {
            flag = false;
            break;
        }
        if (cur == next) {
            total++;
        } else {
            total++;
            ans *= modpow(prev_total, total, mod);
            ans %= mod;
            prev_total = total;
            total = 0;
        }
        // cout << "prev: " << prev_total << ", total: " << total << endl;
    }

    if (!flag) {
        cout << 0 << endl;
        return 0;
    } else {
        cout << ans << endl;
    }
};
