/** author: kicker
*   created: 31-08-2022 09:47
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

ll score1(string s) {
	ll s1 = 0;
    loop(i, 0, s.size()) s1 += s[i] - 96;
    return s1;
}

void solve() {
    string s; ll n, sum = 0;
    cin >> s;
    cin >> n;
    string x = "";

    ll score = 0;
    loop(i, 0, s.size()) score += s[i] - 96;
    if (score <= n) {
    	cout << s line;
    	return;
    }

    vll sc;
    loop(i, 0, s.size()) sc.pb(s[i] - 96);
    sort(all(sc));
    // print(sc);
    // cout << score1(s) line;

    map<ll, ll> cnt;
    loop(i, 0, sc.size()) cnt[sc[i]]++;

    rrep(i, sc.size() - 1, 0) {
    	if (score <= n) break;
    	score -= sc[i];
    	cnt[sc[i]]--;
    }
    
    if (score <= n) {
    	loop(i, 0, s.size()) {
    		if (cnt[s[i] - 96] >= 1) {
    			cout << s[i];
    			cnt[s[i] - 96]--;
    		}
    	}
    	cout line;
    }
    else cout line;
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