/**
 * author: theKicker
 * date: 2022-01-13 16:52:39 
**/
// leetcode 744
#include <bits/stdc++.h>
using namespace std;
#define in cin >>
#define out cout <<
#define outLn(n) cout << n << endl
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define pb push_back
#define pp pop_back
#define si set<int>
#define mii map<int, int>

char nextGreatestLetter(vector<char>& letters, char target) {
    int n = target;
    int s = 0;
    int e = letters.size() - 1;
    if(letters[e] <= target) return letters[0];
    int mid;
    while (s <= e) {
        mid = s + (e-s)/2;
        if (letters[mid] > target) {
            e = mid-1;
        }
        else {
            s = mid+1;
        }
    }
    return letters[s];
}

int main(){
    vc letters{'a', 'b', 'c', 'd', 'e'};
    char ch = 'b';
    char res = nextGreatestLetter(letters, ch);
    outLn(res);
}