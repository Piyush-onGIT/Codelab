/**
 * @author: kicker
 * @date: 14:56, 06 April 2022
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define line << endl
#define loop(i, x, n) for (long long i = x; i < n; i++)
#define rep(i, x, n) for (int i = x; i < n; i++)
#define f first
#define s second
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

bool isValid(vector<vector<bool>> board, pair<ll, ll> p) {
	ll n = board.size();
    if (p.f >= 0 && p.f < n && p.s >= 0 && p.s < n) return true;
    return false;
}

ll findUnsafe(vector<vector<bool>> board, ll r, ll c) {
	ll ans = 0;
	pair<ll, ll> p1, p2, p3, p4;
	
	p1.f = r + 1; p1.s = c + 2;
	p2.f = r + 1; p2.s = c - 2;
	p3.f = r + 2; p3.s = c + 1;
	p4.f = r + 2; p4.s = c - 1;
	
	if (isValid(board, p1)) ans++;
	if (isValid(board, p2)) ans++;
	if (isValid(board, p3)) ans++;
	if (isValid(board, p4)) ans++;
	
	return ans;
}

void solve() {
	ll n;
	cin >> n;
	loop(i, 1, n + 1) {
		vector<vector<bool>> board(i, vector<bool>(i, 0));
		ll col = 0, row = 0, ways = 0;
		if (i == 1) cout << 0 line;
		else if (i == 2) cout << 6 line;
		else if (i == 3) cout << 28 line;
		else {
			vll unsafes1, unsafes2;
			for (ll k = 0; k < i; k++) {
				unsafes1.pb(findUnsafe(board, 0, k));
				unsafes2.pb(findUnsafe(board, i - 2, k));
			}
			
			ll ways = 0;
			ll tmp = (i - 1) - 2;
			tmp += (i - 1) * i - findUnsafe(board, 0, 2);
			
			while (row < i) {
				if (row >= 0 && row <= i - 3 && col >= 2 && col <= i - 3) {
					ll skip = i - 4;
					col += skip;
					ll last = tmp + (1 - skip);
					ll tmpSafe = ((tmp + last) * skip) / 2;
					ways += tmpSafe;
					tmp -= i;
					
					if (col >= i) {row++; col = 0;}
					continue;
				}
				board[row][col] = 1;
				ll unsafe = findUnsafe(board, row, col);
				ll safePos = (i - 1) - col;
				safePos += ((i - 1) - row) * i - unsafe;
				ways += safePos;
				board[row][col] = 0;
				col++;
				if (col >= i) {row++; col = 0;}
			}
			cout << ways line;
		}
	}
}

int main() {
   ios_base::sync_with_stdio(false);cin.tie(NULL);
  
   #ifndef ONLINE_JUDGE
   freopen("../../input.txt", "r", stdin);
   freopen("../../error.txt", "w", stderr);
   freopen("../../output.txt", "w", stdout);
   #endif
  
   ll t;
   // cin >> t;
   t = 1;
   while(t--) {
      solve();
   }
  
   cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
   return 0;
}