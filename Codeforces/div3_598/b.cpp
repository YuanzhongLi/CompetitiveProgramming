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

void solve(vector<int> v) {
    int op_num = v.size() - 1;
    int base_idx = 0;
    int next_base_idx;
    int swap_num = 1;
    while (op_num > 0 && base_idx < v.size() - 1) {
        rep(i, base_idx, v.size()) {
            if (v[i] == swap_num) {
                next_base_idx = i;
                break;
            }
        }
        for (int i = next_base_idx; i > base_idx; i--) {
            if (v[i] < v[i - 1]) {
                if (op_num == 0) {
                    op_num--;
                    break;
                }
                swap(v[i], v[i - 1]);
                op_num--;
            }
        }
        base_idx = next_base_idx;
        swap_num++;
        // cout << "baseidx: " << base_idx << ", swap_num: " << swap_num << endl;
    }
    rep(i, 0, v.size() - 1) {
        printf("%d ", v[i]);
    }
    printf("%d\n", v[v.size()-1]);
};

int main() {
    int N;
    cin >> N;
    rep(i, 0, N) {
        int n;
        cin >> n;
        vector<int> v(n);
        rep(j, 0, n) {
            scanf("%d", &v[j]);
        }
        solve(v);
    }
};
