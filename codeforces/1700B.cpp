/** author: kicker
*   time: 19-06-2022 14:10
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

string sub(string str1, string str2) {
    string ans = "";
    ll ind = 0;
    ll n = str1.size();

    loop(i, 0, n) {
        ll d = (str1[ind] - '0') - (str2[ind] - '0');
        ans += to_string(d)[0];
        ind++;
    }

    return ans;
}

bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();
 
    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;
 
    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
 
    return false;
}

string findDiff(string str1, string str2)
{
    if (isSmaller(str1, str2))
        swap(str1, str2);
 
    string str = "";
 
    int n1 = str1.length(), n2 = str2.length();
 
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
 
    for (int i = 0; i < n2; i++) {
        int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);
 
        // If subtraction is less then zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // subtract remaining digits of larger number
    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);
 
        // if the sub value is -ve, then make it positive
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}

void solve() {
    ll n;
    cin >> n;
    string n1;
    cin >> n1;
    string n2 = n1;

    ll mx = INT_MIN;

    while (n1.size() != 0) {
        ll dig = n1[0] - '0';
        mx = max(mx, dig);
        n1 = n1.substr(1);
    }

    ll d1 = n2[0] - '0';

    if (mx != 9) {
        if (d1 != mx) {
             string tmp(n, to_string(mx)[0]);
             string ans = sub(tmp, n2);
             cout << ans line;
        }
        else if (d1 == mx) {
            string tmp(n, to_string(mx + 1)[0]);
            string ans = sub(tmp, n2);
            cout << ans line;
        }
    }
    else {
        if (d1 == 9) {
            string tmp(n + 1, '1');
            string ans = findDiff(n2, tmp);
            if (ans[0] == '0') ans = ans.substr(1);
            cout << ans line;
        }
        else {
            string tmp(n, '9');
            string ans = sub(tmp, n2);
            cout << ans line;
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