/** author: kicker
*   created: 07-07-2022 10:04
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

bool palindrome(string str, ll s, ll e) {
	string s1 = "";
	loop(i, s, e + 1) {
		s1 += str[i];
	}
	string tmp = s1;
	reverse(all(s1));
	if (s1 == tmp) return true;
	else return false;
}

void solve(ll t) {
    ll n;
    cin >> n;
    string str;
    cin >> str;
    
    for (ll i = 0; i < n; i++) {
        if (str[i] == '?') {
            if (str[n - i - 1] != '?') {
                ll d = str[n - i - 1] - '0';
                d ^= 1;
                str[i] = to_string(d)[0];
            }
            else {
                str[i] = '1';
                str[n - 1 - i] = '0';
            }
        } 
    }
    ll s = 0, e = 4;
    while (e < n) {
    	if (palindrome(str, s, e)) {
    		cout << "Case #" << t << ": IMPOSSIBLE\n";
    		return;
    	}
    	s++; e++;
    }
    cout << "Case #" << t << ": POSSIBLE\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
    #endif

    ll t = 1;
    cin >> t;
    ll n = 1;
    while(n <= t) {
        solve(n);
        n++;
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}