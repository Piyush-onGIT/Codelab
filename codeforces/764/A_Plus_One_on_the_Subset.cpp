#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define in cin >>
#define out cout <<
#define outLn(n) cout << n << endl
#define vi vector<int>
#define pb push_back
#define vii vector<int64_t>
#define vc vector<char>
#define si set<int>
#define mii map<int, int>

int main(){
    int t;
    in t;
    while (t--) {
        int cnt = 0;
        int n;
        in n;
        int arr[n];
        for (int i = 0; i < n; i++) in arr[i];
        sort(arr, arr+n);
        outLn(arr[n-1] - arr[0]);
    }
}