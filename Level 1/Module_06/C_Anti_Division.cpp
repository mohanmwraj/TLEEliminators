//**********************************************************************************
// pbm : https://atcoder.jp/contests/abc131/tasks/abc131_c
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

    [1, N] -> [N/x] means there are N/x numbers which are divisible by x in range 1 to N.
    [1, 11] -> [11/3] = 3, numbers are 3, 6, 9. There are 3 numbers which are divisible by 3 in the range.

    Simply count numbers from [1, B] divisible by C or D, then subtract [1, A-1] results.
    if the number is divisible by both C and D, then it is counted twice. So we need to subtract those numbers once. 
    Take LCM of C and D.

*/

ll a, b;

ll gcd(ll num1, ll num2){
    if(num2 == 0) return num1;
    return gcd(num2, num1 % num2);
}

ll lcm(ll num1, ll num2){
    return (num1 * num2) / gcd(num1, num2);
}

ll f(ll x){
    ll res = (b / x) - ((a - 1) / x);
    return res;
}

void solve(){
    ll c, d;
    cin >> a >> b >> c >> d;

    ll totalRange = b - a + 1;
    ll removed = f(c) + f(d) - f(lcm(c, d));

    cout << totalRange - removed << endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
