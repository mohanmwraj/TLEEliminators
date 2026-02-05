//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1421/A
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

    Smallest possible value of a ^ x + b ^ x

*/

/*
    check if placing 1 in each bit position increase the sum to maximize (a ^ x) + (b ^ x)

    left most set of a and b will be the best candidate for x, as it will maximize the sum of (a ^ x) + (b ^ x)

    1 1 0 1
      1 0 1 ^
    -----------------
    1 0 0 0

    if a & b is same => we keep same, else we set to zero,
    therefore is a & b.

    a ^ (a & b) + b ^ (a & b) = a + b - 2 * (a & b)

    == a ^ b

  a  1   0
  b  0   0
-----------------
     1   0    --> + = 1

*/

void solve(){
    int a, b;
    cin >> a >> b;

    cout << (a ^ b) << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
