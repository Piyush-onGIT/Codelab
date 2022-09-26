/** author: kicker
*   created: 11-09-2022 02:56
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long                           ll;
#define line                                << endl
#define sep                                 << " " <<
#define sp                                  << " "
#define loop(i, x, n)                       for (ll i = x; i < n; i++)
#define rrep(i, x, n)                       for (ll i = x; i >= n; i--)
#define f                                   first
#define s                                   second
#define all(x)                              x.begin(), x.end()
#define vi                                  vector<int>
#define vs                                  vector<string>
#define vll                                 vector<long long>
#define pb                                  push_back
#define pf                                  push_front
#define vc                                  vector<char>
#define sll                                 set<ll>
#define mll                                 map<ll, ll>
#define pqMax                               priority_queue<ll>
#define pqMin                               priority_queue<int, vector<ll>, greater<ll>>


template <typename T> bool _equal(T a[], ll n) { return std::all_of(a, a+n, [a](T x){ return x==a[0]; }); }
template <typename T> T aMax(T a[], T n) { T mx = a[0]; loop(i, 0, n) mx = max(mx, a[i]); return mx; }
template <typename T> T aMin(T a[], T n) { T mn = a[0]; loop(i, 0, n) mn = min(mn, a[i]); return mn; }
template <typename T> void parr(T a[], ll n) { loop(i, 0, n) cout << a[i] << " "; cout line; }
template <typename T> void print(vector<T> v) { loop(i, 0, v.size()) cout << v[i] << " "; cout line; }

void solve(ll t) {
    ll n, k;
    cin >> n >> k;
    ll a[n], b[n];
    loop(i, 0, n) cin >> a[i];
    loop(i, 0, n) cin >> b[i];

    mll ind1, ind2;
    loop(i, 0, n) ind1[a[i]] = i;
    loop(i, 0, n) ind2[b[i]] = i;

    if (k == 0) {
    	loop(i, 0, n) {
    		if (a[i] != b[i]) {
    			cout << "Case #" << t << ": NO\n";
    			return;
    		}
    	}
    	cout << "Case #" << t << ": YES\n";
    	return;
    }

    loop(i, 0, n) {
    	ll crnt1 = ind1[a[i]];
    	ll crnt2 = ind2[a[i]];

    	if (a[(crnt1 + 1) % n] != b[(crnt2 + 1) % n]) {
    		cout << "Case #" << t << ": NO\n";
    		return;
    	}
    }
	cout << "Case #" << t << ": YES\n";
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
    loop(i, 1, t + 1) {
    	solve(i);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}