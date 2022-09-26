/** author: kicker
*   created: 08-09-2022 23:00
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

bool palindrome(string s) {
	string a = s;
	reverse(all(s));
	if (a == s) return true;
	return false;
}

void solve() {
    string a;
    cin >> a;
    ll n = a.size();

    string a1 = "", b1 = "";
   	ll s = 0, e = n - 1;

   	ll chance = 0;
   	while (s < n and e >= 0 and s <= e) {
   		if (a[s] <= a[e]) {
   			if (chance % 2 == 0) {
   				a1 += a[s];
   				chance = 1;
   				s++;
   			}
   			else {
   				ll diff1 = abs(a[s] - a1[a1.size() - 1]);
   				ll diff2 = abs(a[e] - a1[a1.size() - 1]);

   				if (diff1 < diff2) {
   					b1 += a[s];
   					s++;
   				}
   				else {
   					b1 += a[e];
   					e--;
   				}
   				chance = 0;
   			}
   		}
   		else {
   			if (chance % 2 == 0) {
   				a1 += a[e];
   				chance = 1;
   				e--;
   			}
   			else {
   				ll diff1 = abs(a[s] - a1[a1.size() - 1]);
   				ll diff2 = abs(a[e] - a1[a1.size() - 1]);

   				if (diff1 < diff2) {
   					b1 += a[s];
   					s++;
   				}
   				else {
   					b1 += a[e];
   					e--;
   				}
   				chance = 0;
   			}
   		}
   	}
   	if (palindrome(a)) {
   		cout << "Draw\n";
   		return;
   	}
   	if (a1 < b1) cout << "Alice\n";
   	else if (a1 > b1) cout << "Bob\n";
   	else cout << "Draw\n";
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