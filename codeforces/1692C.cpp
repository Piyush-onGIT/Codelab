/** author: kicker
*   time: 14-06-2022 20:06
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
    char a[8][8];
    loop(i, 0, 8) {
    	loop(j, 0, 8) cin >> a[i][j];
    }

    ll col1 = 0, row1 = 0;
    loop(row, 0, 8) {
    	loop(col, 0, 8) {
    		if (a[row][col] == '#' && a[row - 1][col - 1] == '#' && a[row + 1][col + 1] == '#' &&
    			a[row - 1][col + 1] == '#' && a[row + 1][col - 1] == '#') {
    			cout << row + 1 << " " << col + 1 line;
    			return;
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