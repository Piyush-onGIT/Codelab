/** author: kicker
*   created: 09-08-2022 13:24
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define line << endl
#define loop(i, x, n) for (long long i = x; i < n; i++)
#define rep(i, x, n) for (int i = x; i < n; i++)
#define rrep(i, x, n) for (long long i = x; i >= n; i--)
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define pb push_back
#define vii vector<int64_t>
#define vc vector<char>
#define si set<int>
#define mii map<int, int>
#define pqMax priority_queue<int>
#define pqMin priority_queue<int, vector<int>, greater<int>>
#define pll pair<ll, ll>
const int INF = int(2e9) + 99;

template <typename T> bool _equal(T a[], ll n) { return std::all_of(a, a+n, [a](T x){ return x==a[0]; }); }
template <typename T> T aMax(T a[], T n) { T mx = a[0]; loop(i, 0, n) mx = max(mx, a[i]); return mx; }
template <typename T> T aMin(T a[], T n) { T mn = a[0]; loop(i, 0, n) mn = min(mn, a[i]); return mn; }

vector<pll> valid(pll p1, pll p2, pll p3, pll p4, ll m, vvll path) {
	vector<pll> ans;
	if (p1.f >= 0 && p1.f < 2 && p1.s >= 0 && p1.s < m) {
		ans.pb(p1);
	}
	if (p2.f >= 0 && p2.f < 2 && p2.s >= 0 && p2.s < m) {
		ans.pb(p2);
	}
	if (p3.f >= 0 && p3.f < 2 && p3.s >= 0 && p3.s < m) {
		ans.pb(p3);
	}
	if (p4.f >= 0 && p4.f < 2 && p4.s >= 0 && p4.s < m) {
		ans.pb(p4);
	}
	return ans;
}

void solve() {
    ll m;
    cin >> m;
    vvll a(2, vll(m));
    loop(i, 0, 2) {
    	loop(j, 0, m) cin >> a[i][j];
    }
    vvll b = a;

    // set<pair<ll, ll>> path;
    vector<pll> pth;
    ll i = 0, s = 0, j = 0;
    while (i < 2 * m) {
    	pair<ll, ll> pos1, pos2, pos3, pos4;
    	pos1 = {s + 1, j};
    	pos2 = {s - 1, j};
    	pos3 = {s, j + 1};
    	pos4 = {s, j - 1};

    	vector<pll> ans = valid(pos1, pos2, pos3, pos4, m, a);

    	ll mn = a[ans[0].f][ans[0].s];
    	pll ind = ans[0];

    	loop(i, 1, ans.size()) {
    		a[s][j] = INT_MAX;
    		ll cur = a[ans[i].f][ans[i].s];
    		if (cur < mn) {
    			mn = cur;
    			ind = ans[i];
    		}
    	}

    	pth.pb(ind);
    	i++;
    	s = ind.f; j = ind.s;
    }
    vll path;
    for (auto const &x : pth) {
    	path.pb(b[x.f][x.s]);
    	// cout << b[x.f][x.s] << " ";
        // cout << "(" << x.first << ", " << x.second << ")" << " ";
    }

    ll time = 0, wait = 0;
    loop(i, 0, path.size() - 1) {
    	time = max(path[i] - wait, 1ll * 0);
    	wait += time + 1;
    	// cout << path[i] << " ";
    }
    // cout line;
    cout << wait line;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../error.txt", "w", stderr);
    freopen("../output.txt", "w", stdout);
    #endif

    ll t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}