//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1617/B
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
    GCD of consecutive numbers is 1.

    a + b + c = n
    a  + b = n - c;

    if we make gcd is 1, then a + b = n - 1;
    if n is even, ex: 18 then n - 1 = 17.
    8 + 9 = 17. 
    9 , 8, 1 = 18.

    if n is odd, n - 1, becomes even, two consecutive numbers can't be even. one odd and one even.

    we can't divide a and b equally as (n-1)/2 . because gcd (a, b) == (n - 1) /2 when a and b is equal to (n - 1)/2

    Two consecutive odd numbers have gcd 1, two consecutive even numbers have gcd 2.

    x = (n - 1) / 2;
    ~ x + x = n - 1

    ~ (x - 1) + (x + 1) = n - 1 gcd should be 1
    x is odd: x - 1 & x + 1 is even. two consecutive even numbers have gcd 2. not possible
    x is even: x - 1 & x + 1 is odd. Two consecutive odd numbers have gcd 1

    x is odd: x + 2 & x - 2 is odd and  gcd should be 1, ex: 3 & 7, 5 & 9.
*/

void solve(){
    int n; cin >> n;

    if(n % 2 == 0){
        cout << (n - 1) / 2 << " " << (n-1)/2 + 1 << " 1" << endl;
    } else {
        int curr = (n - 1)/2;
        if(curr % 2 == 0){
            cout << curr - 1 << " " << curr + 1 << " " << 1 << endl;
        } else {
            cout << curr - 2 << " " << curr + 2 << " " << 1 << endl;
        }
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
