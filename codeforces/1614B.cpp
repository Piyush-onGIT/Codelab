/** author: kicker
*   created: 04-09-2022 09:49
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

bool cmp(pair<ll, ll>& a, pair<ll, ll>& b) {
    return a.second < b.second;
}

vector<pair<ll, ll>> sort(vector<pair<ll, ll>> A) {
    sort(A.begin(), A.end(), cmp);
    return A;
}

void solve() {
    ll n;
    cin >> n;
    ll a[n];
    loop(i, 0, n) cin >> a[i];

    vector<pair<ll, ll>> cnt;
    loop(i, 0, n) cnt.pb({i + 1, a[i]});
    cnt = sort(cnt);

    vll ans(n + 1);
    ans[0] = 0;
    ll last = 0;
    ll sum = 0;

    vector<pair<ll, ll>>::reverse_iterator itr = cnt.rbegin();

    for (itr; itr != cnt.rend(); itr++) {
    	if (last == 0) {
    		ans[itr -> f] = last + 1;
    		last++;
    		sum += 2 * abs(0 - ans[itr -> f]) * itr -> s;
    	}
    	else if (last > 0) {
    		ans[itr -> f] = -last;
    		last = -last;
    		sum += 2 * abs(0 - ans[itr -> f]) * itr -> s;
    	}
		else {
			ans[itr -> f] = abs(last) + 1;
			last = abs(last) + 1;
			sum += 2 * abs(0 - ans[itr -> f]) * itr -> s;
		}    	
    }
    cout << sum line;
    print(ans);
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