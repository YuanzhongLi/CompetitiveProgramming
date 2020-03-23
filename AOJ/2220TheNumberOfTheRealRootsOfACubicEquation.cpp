#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
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
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

typedef pair<int, int> PI;
typedef pair<ll, ll> PLL;

int POWINT(int x, int n) {
  int ret = 1;
  rep(i, 0, n) ret *= x;
  return ret;
};

ll POWLL(int x, int n) {
  ll ret = 1;
  rep(i, 0, n) ret *= x;
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

long double a, b, c, d;
int n;

long double calc(long double pos) {
	return a * pos * pos * pos + b * pos * pos + c * pos + d;
}

long double find_answer(long double L, long double R, bool ok) {
	long double p1 = calc(L), p2 = calc(R);
  if (p1 > p2) swap(p1, p2);
	if (!(p1 <= 1e-14 && -1e-14 <= p2)) return -1e9;

	long double M;
	for (int i = 0; i < 100; i++) {
		M = (L + R) / 2;
		long double ret = calc(M);
		bool res = false;

    if (ret > 0) res = true;
		if ((ok ^ res) == false) R = M;
		else L = M;
	}
	return M;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b >> c >> d;
		d /= a; c /= a; b /= a; a = 1;

		long double A = 3.0 * a, B = 2.0 * b, C = c; // 微分
		vector<tuple<long double, long double, bool>> T;
		if (B * B - 4.0 * A * C < -1e-5) {
			T.push_back(make_tuple(-10000, 10000, true));
		}
		else {
			long double V = sqrtl(B * B - 4.0 * A * C); // sqrtl long double用のsqrt
			long double W1 = (-B - V) / (2.0 * A);
			long double W2 = (-B + V) / (2.0 * A);
			T.push_back(make_tuple(-10000, W1, true));
			T.push_back(make_tuple(W1, W2, false));
			T.push_back(make_tuple(W2, 10000, true));
		}
		vector<long double>U;
		for (int j = 0; j < T.size(); j++) {
			long double V = find_answer(get<0>(T[j]), get<1>(T[j]), get<2>(T[j]));
			if (V >= -1e8) U.push_back(V);
		}
		sort(U.begin(), U.end());

		int t1 = 0, t2 = 0;
		for (int j = 0; j < U.size(); j++) {
			if (U[j] < -1e-5) t1++;
			else t2++;
		}
		if (fabs(d) < 1e-10) t2--;
		if (fabs(c) < 1e-10 && fabs(d) < 1e-10) t2--;
		if (fabs(b) < 1e-10 && fabs(c) < 1e-10 && fabs(d) < 1e-10) t2--;
		cout << t2 << " " << t1 << endl;
	}
	return 0;
}
