/** author: kicker
*   time: 12-06-2022 13:04
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
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long>
#define pb push_back
#define vii vector<int64_t>
#define vc vector<char>
#define si set<int>
#define mll map<ll, ll>
#define pqMax priority_queue<int>
#define pqMin priority_queue<int, vector<int>, greater<int>>
const int INF = int(2e9) + 99;

void solve() {
    ll n;
    cin >> n;
    ll a[n];
    loop(i, 0, n) cin >> a[i];

    map<ll, ll> cnt;
    loop(i, 0, n) cnt[a[i]]++;

    loop(i, 0, n) {
    	if (cnt[a[i]] < 2) {
    		cout << -1 line;
    		return;
    	}
    }
    
    ll prev = 0;
    for (auto i : cnt) {
        ll c = i.s;
        cout << c + prev;
        cout << " ";
        ll t = 1;
        loop(i, 0, c - 1) {
            cout << t + prev << " ";
            t++;
        }
        prev += c; 
    }
    cout line;
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