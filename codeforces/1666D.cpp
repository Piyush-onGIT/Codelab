/** author: kicker
*   created: 10-09-2022 20:18
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

void solve() {
    string s, t;
    cin >> s >> t;
    map<char, ll> c1, c2;

    loop(i, 0, s.size()) c1[s[i]]++;
    loop(i, 0, t.size()) c2[t[i]]++;

    for (auto i : c1) {
    	if (c2.find(i.f) != c2.end() and i.s - c2[i.f] < 0) {
    		cout << "NO\n";
    		return;
    	} 
    }

    string tmp = "";
    loop(i, 0, s.size()) if (c2.find(s[i]) != c2.end()) tmp += s[i];

    for (auto i : c2) {
    	ll cnt = c1[i.f] - i.s;
    	ll j = 0, x = 0;
    	while (j < cnt) {
    		if (tmp[x] == i.f) {
    			tmp[x] = '1';
    			j++;
    		}
    		x++;
    	}
    }

    string final = "";
    loop(i, 0, tmp.size()) if (tmp[i] != '1') final += tmp[i];

    if (final == t) cout << "YES\n";
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