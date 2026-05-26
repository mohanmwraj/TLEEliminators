//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1881/A
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

/*

    Constructing x0 to x5 by doubling x, check if s is a substring using check(s, xi);
    output minimum i where true;

    The argument should not go above 25. 

    x = a, s = a....a (length = 25)

    x.size() < s.size()

    x = a -> 1st operation -> x = aa
    2nd operation -> x = aaaa
    3rd operation -> x = aaaaaaaa
    4th operation -> x = aaaaaaaaaaaaaaaa
    5th operation -> x = aaaaaaaaaaaaaaaaaaaaaaaa (length = 32)

    
    Time complexity: O(n * m) where n is the length of xi and m is the length of s. 
    Since xi can be at most 64 times the length of x, this is efficient for our constraints.
    Space complexity: O(n) for storing xi.

    O(2^5*n*n) = O(32*n*n) = O(n*n).
*/

bool check(string s, string x){
    return x.find(s) != string::npos;

    // if(x.size() < s.size()){
    //     return false;
    // }

    // for(int i = 0; i <= x.size() - s.size(); i++){ //n - m + 1 iterations, where n is size of x and m is size of s.
    //     if(x.substr(i, s.size()) == s){
    //         return true;
    //     }
    // }
    // return false;
}

void solve(){
    ll n, m;
    cin >> n >> m;

    string x; cin >> x;
    string s; cin >> s;

    string x0 = x;
    string x1 = x0 + x0;
    string x2 = x1 + x1;
    string x3 = x2 + x2;
    string x4 = x3 + x3;
    string x5 = x4 + x4;

    ll ans = -1;
    //if(x0.find(s) != string::npos){

    if(check(s, x0)){
        ans = 0;
    } else if(check(s, x1)){
        ans = 1;
    } else if(check(s, x2)){
        ans = 2;
    } else if(check(s, x3)){
        ans = 3;
    } else if(check(s, x4)){
        ans = 4;
    } else if(check(s, x5)){
        ans = 5;
    }
    cout << ans << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
