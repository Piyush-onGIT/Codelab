/** author: kicker
*   time: 16-06-2022 10:40
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

bool equal(ll a[], ll b[], ll n) {
	loop(i, 0, n) if (a[i] != b[i]) return false;
	return true;
}

void solve() {
    ll n;
    cin >> n;
    ll a[n], b[n];
    loop(i, 0, n) cin >> a[i];
    loop(i, 0, n) cin >> b[i];

    if (equal(a, b, n)) {
    	cout << "YES\n";
    	return;
    }

    ll diff = -1, flag = 0;
    loop(i, 0, n) {
    	if (b[i] != 0) {
            flag = 1;
    		diff = a[i] - b[i];
    		break;
    	}
    }

    if (diff >= 0 && n == 1) {
    	cout << "YES\n";
    	return;
    }

    else if (diff == -1 && flag == 0) cout << "YES\n";

    else if (diff >= 0) {
    	loop(i, 0, n) {
    		if (a[i] - diff < 0) a[i] = 0;
    		else if (a[i] != 0) a[i] -= diff;
    	}

    	// loop(i, 0, n) cout << a[i] << " ";

    	if (equal(a, b, n)) cout << "YES\n";
    	else cout << "NO\n";
    }
    else cout << "NO\n";
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