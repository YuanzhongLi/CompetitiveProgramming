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
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> plat(m);
    int plat_zones = 0;
    rep(i, 0, m) {
        scanf("%d", &plat[i]);
        plat_zones += plat[i];
    }

    if (d == 1) {
        if (n != plat_zones) {
            cout << "NO" << endl;
            return 0;
        } else {
            cout << "YES" << endl;
            rep(i, 0, m) {
                int pl = plat[i];
                rep(j, 0, pl) {
                    if (i == m - 1 && j == pl - 1) {
                        printf("%d\n", i+1);
                    } else {
                        printf("%d ", i+1);
                    }
                }
            }
            return 0;
        }
    }

    int water_zones = n - plat_zones;
    int slashs = water_zones / (d - 1);
    int remainder = water_zones % (d - 1);

    // cout << "water_zones: " << water_zones << endl;
    // cout << "splashs: " << slashs << endl;
    // cout << "remainder: " << remainder << endl;

    if (water_zones > (m+1) * (d - 1)) {
        cout << "NO" << endl;
        return 0;
    }


    int cur_point = 0;
    int plat_idx = 0;

    vector<int> ans(n, 0);
    rep(i, 0, slashs) {
        rep(j, 0, d - 1) {
            ans[cur_point] = 0;
            cur_point++;
        }
        if (plat_idx > m - 1) {
            break;
        }
        int pl = plat[plat_idx];
        rep(j, 0, pl) {
            ans[cur_point] = plat_idx+1;
            cur_point++;
        }
        plat_idx++;
    }

    rep(i, 0, remainder) {
        ans[cur_point] = 0;
        cur_point++;
    }

    rep(i, cur_point, n) {
        if (plat_idx > m - 1) {
            break;
        }
        int pl = plat[plat_idx];
        rep(j, 0, pl) {
            ans[cur_point] = plat_idx+1;
            cur_point++;
        }
        plat_idx++;
    }

    cout << "YES" << endl;
    rep(i, 0, n - 1) {
        printf("%d ", ans[i]);
    }
    printf("%d\n", ans[n - 1]);

    return 0;
};
