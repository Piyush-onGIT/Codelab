/** author: kicker
*   created: 11-08-2022 20:09
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

template <typename T> bool _equal(T a[], ll n) { return std::all_of(a, a+n, [a](T x){ return x==a[0]; }); }
template <typename T> T aMax(T a[], T n) { T mx = a[0]; loop(i, 0, n) mx = max(mx, a[i]); return mx; }
template <typename T> T aMin(T a[], T n) { T mn = a[0]; loop(i, 0, n) mn = min(mn, a[i]); return mn; }

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    char c = s[0];
    vll blocks;
    ll count = 1;
    loop(i, 1, n) {
    	if (s[i] != c) {
    		blocks.pb(count);
    		count = 1;
    		c = s[i];
    	}
    	else count++;
    }
    blocks.pb(count);

    if (b >= 0) {
    	cout << n * (a + b) line;
    }
    else {
    	ll score = 0;
    	ll n1 = blocks.size();
    	if (n1 == 1) {
    		score = a * n + b;
    	}
    	else if (n1 == 2) {
    		score = a * blocks[0] + b;
    		score += a * blocks[1] + b;
    	}
    	else if (n1 == 3) {
    		score = a * blocks[1] + b;
    		score += a * (blocks[0] + blocks[2]) + b;
    	}
    	else {
			ll i = 1;
	    	while (blocks.size() > 3) {
				vll::iterator itr = blocks.begin();
	    		score += a * blocks[i] + b;
	    		blocks[i] = blocks[i - 1] + blocks[i + 1];

	    		itr++; itr++;
	    		blocks.erase(itr);
	    		blocks.erase(blocks.begin());
	    	}

	    	if (blocks.size() == 1) {
    			score += a * blocks.size() + b;
	    	}
	    	else if (blocks.size() == 2) {
	    		score += a * blocks[0] + b;
	    		score += a * blocks[1] + b;
	    	}
	    	else {
	    		score += a * blocks[1] + b;
	    		score += a * (blocks[0] + blocks[2]) + b;
	    	}
    	}
    	cout << score line;
    }
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