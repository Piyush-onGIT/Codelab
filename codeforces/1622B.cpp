/** author: kicker
*   created: 15-08-2022 00:18
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
    ll n;
    cin >> n;
    ll a[n];
    loop(i, 0, n) cin >> a[i];
    
    string vote;
    cin >> vote;

    ll zero = 0, one = 0;
    loop(i, 0, n) {
    	if (vote[i] == '0') zero++;
    	else one++;
    }

    set<ll> like, dislike;
    loop(i, 0, zero) dislike.insert(i + 1);
    loop(i, 0, one) like.insert(i + 1 + zero);

    vll per(n);
    loop(i, 0, n) {
    	if (vote[i] == '0') {
    		ll mn = *dislike.begin(), mx = *dislike.rbegin();
    		if (a[i] >= mn && a[i] <= mx) {
    			per[i] = a[i];
    			dislike.erase(a[i]);
    		}
    		else {
    			per[i] = mx;
    			dislike.erase(mx);
    		}
    	}
    	else {
    		ll mn = *(like.begin()), mx = *like.rbegin();
    		if (a[i] >= mn && a[i] <= mx) {
    			per[i] = a[i];
    			like.erase(a[i]);
    		}
    		else {
    			per[i] = *(like.begin());
    			like.erase(like.begin());
    		}
    	}
    }
    loop(i, 0, n) cout << per[i] << " ";
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