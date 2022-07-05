/** author: kicker
*   time: 15-06-2022 20:35
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

void solve() {
    ll n, x;
    cin >> n >> x;
    
    if (n % 2 == 0) {
        if (x > n / 2) cout << -1 line;
        else {
            string s(x, '?');
            ll c = 97;
            loop(i, 0, x) {
                s[i] = c;
                c++;
            }
            char tmp = s[x - 1];
            string ans;
            ans += s;
            reverse(s.begin(), s.end());
            ans += s;
            
            if (ans.size() == n) cout << ans line;
            else {
                ll rem = n - ans.size();
                reverse(s.begin(), s.end());
                cout << s;
                loop(i, 0, rem) cout << tmp;
                reverse(s.begin(), s.end());
                cout << s line;
            }
        }
    }
    else {
        if (x > ceil(n / (double) 2)) cout << -1 line;
        else {
            string s(x - 1, '?');
            ll c = 97;
            loop(i, 0, x - 1) {
                s[i] = c;
                c++;
            }
            string ans;
            ans += s;
            ans += c;
            reverse(all(s));
            ans += s;

            if (ans.size() == n) cout << ans line;
            else {
            	ll rem = n - 2 * s.size();
            	cout << s;
            	loop(i, 0, rem) {
            		char tmp = c;
            		cout << tmp;
            	}
            	reverse(all(s));
            	cout << s line;
            }
        }
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