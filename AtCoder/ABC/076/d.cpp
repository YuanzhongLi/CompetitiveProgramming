#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
#define lbidx(x, y) lower_bound(x.begin(), x.end(), y) - x.begin()
#define ubidx(x, y) upper_bound(x.begin(), x.end(), y) - x.begin()
#define llbidx(x, y, z) lower_bound(x.begin(), x.end(), z) - lower_bound(x.begin(), x.end(), y) // 二要素間の距離
#define deg2rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad2deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)
#define Find(set, element) set.find(element) != set.end()
#define Decimal(x) printf("%.10f\n", x) // 小数点を10桁まで表示
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << "\n";
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define endl "\n"
// gcj print用
#define Case(x) printf("Case #%d: ", x);

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<int>>> vvvl;
typedef vector<PI> vpi;
typedef vector<vector<PI>> vvpi;
typedef vector<vector<vector<PI>>> vvvpi;
typedef vector<PLL> vpl;
typedef vector<vector<PLL>> vvpl;
typedef vector<vector<vector<PLL>>> vvvpl;

int POWINT(int x, int n) {
  int ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
};

ll POWLL(ll x, int n) {
  ll ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
};

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

void print() {
  cout << endl;
}

template <class T>
void print(vector<T> &vec) {
  for (auto& a : vec) {
    cout << a;
    if (&a != &vec.back()) cout << " ";
  }
  cout << endl;
}

template <class T>
void print(vector<T> &vec, ll k){
   ll n = vec.size();
   k = min(k, n);
   rep(i, 0, k-1) cout << vec[i] << " ";
   cout << vec[k-1] << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
  for (auto& vec : df) {
    print(vec);
  }
}

template<class T, class U>
void print(pair<T,U> &p){
  cout << p.first << " " << p.second << "\n";
}

class SEGMENT {
public:
  double in, out;
  double dist;
  SEGMENT() {}
  SEGMENT(double in, double out, double dist): in(in), out(out), dist(dist) {}
};

vector<double> T(105), V(105);
vector<SEGMENT> segs(105);

void rec(int i, double v) {
  if (i < 0) return;
  auto seg = segs[i];

  if (V[i]-seg.in + V[i]-v < T[i]) {
    seg.out = v;
    seg.dist = V[i] * T[i] - (V[i]-seg.in)*(V[i]-seg.in)/2.0 \
    - (V[i]-v)*(V[i]-v)/2.0;

    segs[i] = seg;
    return;
  } else if (v+T[i] > seg.in) {
    seg.out = v;

    double tmp_t =  (T[i] - (seg.in-v))/2.0;

    seg.dist = tmp_t * tmp_t + seg.in * tmp_t * 2.0 \
    + v * (seg.in-v) + (seg.in-v)*(seg.in-v)/2.0;

    segs[i] = seg;
    return;
  } else {
    seg.in = v + T[i];
    seg.out = v;
    seg.dist = v * T[i] + T[i]*T[i]/2.0;
    segs[i] = seg;
    rec(i-1, segs[i].in);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  rep(i, 0, n) {
    cin >> T[i];
  }

  rep(i, 0, n) {
    cin >> V[i];
  }

  V[n] = 0.0;

  SEGMENT first;
  if (T[0] > V[0]) {
    first.in = 0.0;
    first.out = V[0];
    first.dist = (T[0]+(T[0]-V[0]))*V[0]/2.0;
  } else {
    first.in = 0.0;
    first.out = T[0];
    first.dist = T[0]*T[0]/2.0;
  }

  segs[0] = first;

  rep(i, 1, n+1) {
    auto prev_seg = segs[i-1];
    auto cur_seg = segs[i];
    auto v = V[i];
    auto t = T[i];

    if (prev_seg.out > v) {
      // debug(i);
      cur_seg.in = cur_seg.out = v;
      cur_seg.dist = v * t;
      segs[i] = cur_seg;
      rec(i-1, v);
    } else {
      cur_seg.in = prev_seg.out;
      if ((v - cur_seg.in) > t) {
        cur_seg.out = cur_seg.in + t;
        cur_seg.dist = (cur_seg.in + cur_seg.out)*t/2.0;
      } else {
        cur_seg.out = v;
        cur_seg.dist = (cur_seg.in + v)*(v-cur_seg.in)/2.0 \
        + (t-(v-cur_seg.in))*v;
      }
      segs[i] = cur_seg;
    }
  }

  double ans = 0.0;
  rep(i, 0, n) {
    ans += segs[i].dist;
  }

  Decimal(ans);

  return 0;
};
