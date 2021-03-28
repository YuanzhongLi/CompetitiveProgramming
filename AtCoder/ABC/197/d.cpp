// #define LOCAL
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,s,n) for (int i = (ll)s; i < (ll)n; i++)
#define rrep(i,n,e) for (int i = (ll)n; i > (ll)e; i--)
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j
// #define M_PI 3.14159265358979323846 // CF
#define deg2rad(deg) ((((double)deg)/((double)360)*2*M_PI))
#define rad2deg(rad) ((((double)rad)/(double)2/M_PI)*(double)360)
#define Find(set, element) set.find(element) != set.end()
#define Decimal(x) cout << fixed << setprecision(10) << x << endl; // print Decimal number 10 Rank
#define endl "\n"
#define Case(x) printf("Case #%d: ", x); // gcj

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
typedef vector<PI> vpi;
typedef vector<vector<PI>> vvpi;
typedef vector<PLL> vpl;
typedef vector<vector<PLL>> vvpl;
typedef vector<char> vch;
typedef vector<vector<char>> vvch;

constexpr ll INF = 1001002003004005006ll;
constexpr int n_max = 2e5+10;

template<class T>
inline bool chmax(T &a, T b) { if(a<b) { a=b; return true; } return false; };
template<class T>
inline bool chmin(T &a, T b) { if(a>b) { a=b; return true; } return false; };

template<class T, class U>
T POW(T x, U n) {T ret=1; while (n>0) {if (n&1) {ret*=x;} x*=x; n>>=1;} return ret;};

// debug
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) {return '"' + s + '"';};
string to_string(const char c) {return to_string((string) &c);};
string to_string(bool b) {return (b ? "true" : "false");};
template <size_t N>
string to_string(bitset<N> v){
  string res = "";
  for(size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
  return res;
};
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for(const auto &x : v) {
    if(!first) res += ", ";
    first = false; res += to_string(x);
  }
  res += "}";
  return res;
};
template <typename A, typename B>
string to_string(pair<A, B> p){return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}

void debug_out() {cerr << endl;};
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); };

void LINE_OUT() {
  cout << "--------------" << endl;
};

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define LINE LINE_OUT();
#else
#define debug(...) 71
#define LINE 71;
#endif

void print() { cout << endl; }
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(tail) != 0) cout << " ";
  print(forward<Tail>(tail)...);
};

template <class T>
void print(vector<T> &vec) {
  for (auto& a : vec) {
    cout << a;
    if (&a != &vec.back()) cout << " ";
  }
  cout << endl;
};

template <class T>
void print(vector<vector<T>> &df) {
  for (auto& vec : df) {
    print(vec);
  }
};

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

class Point {
  public:
  long double x, y;

  Point(long double x = 0, long double y = 0): x(x), y(y) {}

  Point operator + (Point p) { return Point(x + p.x, y + p.y); }
  Point operator - (Point p) { return Point(x - p.x, y - p.y); }
  Point operator * (long double a) { return Point(a * x, a * y); }
  Point operator / (long double a) { return Point(x / a, y / a); }

  long double abs() { return sqrtl(norm()); }
  long double norm() { return x * x + y * y; }

  bool operator < (const Point &p) const {
    return x != p.x ? x < p.x : y < p.y;
  }

  bool operator == (const Point &p) const {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }
};

std::ostream &operator<<(std::ostream &out, const Point &p) {
  out << '(' << p.x << ", " << p.y << ')';
  return out;
}

class Circle {
  public:
    Point c;
    long double r;
    Circle(Point c = Point(), long double r = 0.0): c(c), r(r) {}
};

struct Segment {
  Point p1, p2;
};

typedef Point Vector;
typedef Segment Line;

long double norm(Vector a) {
  return a.x * a.x + a.y * a.y;
};

long double abs(Vector a) {
  return sqrtl(norm(a));
};

// 内積
long double dot(Vector a, Vector b) {
  return a.x * b.x + a.y * b.y;
};

// 外積
long double cross(Vector a, Vector b) {
  return a.x * b.y - a.y * b.x;
};

// 直交判定
bool isOrthogonal(Vector a, Vector b) {
  return equals(dot(a, b), 0.0);
};

// 並行判定
bool isParallel(Vector a, Vector b) {
  return equals(cross(a, b), 0.0);
};

// 射影
Point project(Segment s, Point p) {
  Vector base = s.p2 - s.p1;
  long double r = dot(p - s.p1, base) / base.norm();
  return s.p1 + base * r;
};

// 反射
Point reflect(Segment s, Point p) {
  return p + (project(s, p) - p) * 2.0;
};

// 回転 ang: radian
Point rot(Point p, long double ang) {return Point(cos(ang) * p.x - sin(ang) * p.y, sin(ang) * p.x + cos(ang) * p.y); };
Point rot90(Point p) { return Point(-p.y, p.x); };

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ld N; cin >> N;
  ld x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1;
  ld cx = (x0+x1)/2.0, cy = (y0+y1)/2.0;
  Point C(cx, cy);
  Point c0(x0-cx, y0-cy);
  Point c1 = rot(c0, deg2rad(360.0/N));
  Point ans = C + c1;
  cout << fixed << setprecision(10) << ans.x << " ";
  Decimal(ans.y);



  return 0;
};
