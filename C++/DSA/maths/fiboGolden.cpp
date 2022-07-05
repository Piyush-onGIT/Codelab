/**
 * @authors: kicker
 * @date: 14:41, 23 February 2022
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define in cin >>
#define out cout <<
#define outLn(n) cout << n << endl
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define vii vector<int64_t>
#define vc vector<char>
#define si set<int>
#define mii map<int, int>
#define pqMax priority_queue<int>
#define pqMin priority_queue<int, vector<int>, greater<int>>

int main(){
	// get the nth fibonacci number in O(1)
    for (int n = 0; n < 11; n++) {
    	cout << (pow((1 + pow(5, 0.5))/2, n) - pow((1 - pow(5, 0.5))/2, n))/pow(5, 0.5) << endl;
	}
}
