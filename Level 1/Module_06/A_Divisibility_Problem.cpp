//**********************************************************************************
// pbm : https://codeforces.com/contest/1328/problem/A
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

    To make a number 'a' divisible by 'b', we need to add the smallest number 'x' such that (a + x) % b == 0.
    This is equivalent to finding x = b - (a % b) when a is not divisible by b.
    If a is already divisible by b, then x = 0.

    Example:
    a = 10, b = 6
    a % b = 4
    x = b - (a % b) = 6 - 4 = 2
    So, adding 2 to 10 makes it divisible by 6.

    a = 12, b = 4
    a % b = 0
    x = 0
    So, no addition is needed as 12 is already divisible by 4.

*/
void solve(){
    int a, b;
    cin >> a >> b;

    if(a%b == 0){
        cout << 0 << endl;
    } else {
        cout << (b - (a%b)) << endl;
    }
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
