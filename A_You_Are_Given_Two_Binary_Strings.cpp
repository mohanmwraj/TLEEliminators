//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1202/A
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

    To make binary string lexicographically smallest, 
    right shift every bit until the first '1' become '0'.

    Time limit per test: 2 seconds
    Memory limit: 256 megabytes

    Total Time Complexity: 1sec = 10^8 ops
    2sec = 2 * 10^8 ops
    Each test will have 10^ test cases, therefore each test case should be solved in 2 * 10^8 / 10^2 = 2 * 10^6 ops

    Allowed Time Complexity: O(n)

    Sk = f(x) + f(y).2^k

    when you multiply a binary string by 2^k, you are essentially left shifting by k bits of the string.

*/

void solve(){
    
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
