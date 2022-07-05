/**
 * @author: kicker
 * @date: 01:07, 06 April 2022
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define line << endl
#define loop(i, x, n) for (long long i = x; i < n; i++)
#define rep(i, x, n) for (int i = x; i < n; i++)
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

void solve() {
	ll n;
	cin >> n;
	ll arr[n];
	loop(i, 0, n) cin >> arr[i];
	
	ll cnt = 0;
	loop(i, 1, n) {
		if (arr[i] < arr[i - 1]) {
			cnt += arr[i - 1] - arr[i];
			arr[i] = arr[i - 1];
		}
	}
	// if (arr[n - 1] < arr[n - 2]) cnt += arr[n - 2] - arr[n - 1];
	
	// loop(i, 0, n) cout << arr[i] << " ";
	// cout line;
	cout << cnt line;
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