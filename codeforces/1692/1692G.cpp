/** author: kicker
*   time: 15-06-2022 02:04
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

int findSubarraySum(vll arr, int sum) {
    ll n = arr.size();
    unordered_map<int, int> prevSum;
    int res = 0;
 
    int currSum = 0;
 
    for (int i = 0; i < n; i++) {
 
        currSum += arr[i];

        if (currSum == sum)
            res++;
 
        if (prevSum.find(currSum - sum) != prevSum.end())
            res += (prevSum[currSum - sum]);
 
        prevSum[currSum]++;
    }
 
    return res;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    ll a[n];
    loop(i, 0, n) cin >> a[i];

    vll pairs;
    loop(i, 0, n - 1) {
        if (a[i] < 2 * a[i + 1]) pairs.pb(1);
        else pairs.pb(0);
    }
    
    ll prevSum = 0;
    ll ind = 0, prevInd = 0;
    loop(i, ind, k) prevSum += pairs[i];

    ll sum;
    loop(i, 1, pairs.size()) {
        sum -= pairs[prevInd];
        sum += 
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