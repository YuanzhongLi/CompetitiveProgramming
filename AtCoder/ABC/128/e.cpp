#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,n) for (int i = (int)s; i < (int)n; i++)
#define ll long long
#define pb push_back
#define All(x) x.begin(), x.end()
#define Range(x, i, j) x.begin() + i, x.begin() + j

int lbidx(vector<int> x, int y) {
  auto itr = lower_bound(x.begin(), x.end(), y);
  int idx = itr - x.begin();
  return idx;
};

int upidx(vector<int> x, int y) {
  auto itr = upper_bound(x.begin(), x.end(), y);
  int idx = itr - x.begin();
  return idx;
}

ll n,q;
ll s[200100],t[200100],x[200100];
ll d[200100];
struct road {
	ll sx;
	ll add;
	ll dis;
	road(ll _sx,ll _add,ll _dis){
		sx = _sx;
		add = _add;
		dis = _dis;
	}
	bool operator < (road &r2){
		if (sx != r2.sx){
			return sx < r2.sx;
		} else {
			return add < r2.add;
		}
	}
};
vector<road> rr;
ll ans[200100];
int main(){
	cin >> n >> q;
	rep(i, 0, n) cin >> s[i] >> t[i] >> x[i];
	rep(i, 0, q) cin >> d[i];
	rep(i, 0, n) {
		rr.pb(road(s[i]-x[i],1,x[i]));
		rr.pb(road(t[i]-x[i],-1,x[i]));
	}
	sort(All(rr));

	set<ll> T;
  int t = 0;
	rep(i, 0, q){
    while(t < rr.size() && rr[t].sx <= d[i]) {
      if (rr[t].add == 1) {
        T.insert(rr[t].dis);
      } else {
        T.erase(rr[t].dis);
      }
      t++;
    }
		if(T.empty()) cout << -1 << endl;
		else cout<< *T.begin() << endl;
	}

	return 0;
}
