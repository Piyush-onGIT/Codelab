/** author: kicker
*   time: 17-06-2022 11:25
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
#define pb push_back
#define vii vector<int64_t>
#define vc vector<char>
#define si set<int>
#define mii map<int, int>
#define pqMax priority_queue<int>
#define pqMin priority_queue<int, vector<int>, greater<int>>
const int INF = int(2e9) + 99;

// sliding window
ll subSum(ll a[], ll n, ll k) {
	ll first = 0;
	loop(i, 0, k) first += a[i];

	ll mx = first, ind = 0;
	loop(i, k, n) {
		first += a[i] - a[i - k];
		if (first > mx) {
			mx = first;
			ind = i - k + 1;
		}
	}
	return ind;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    string str;
    cin >> str;

    ll a[n];
    ll i = 0;
	loop(i, 0, n) {
		if (str[i] == 'B') a[i] = 1;
		else a[i] = -1;
	}

	ll ans = subSum(a, n, k);
	// cout << ans line;
	ll w = 0;
	loop(i, ans, ans + k) {
		if (a[i] == -1) w++;
	}
	cout << w line;
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