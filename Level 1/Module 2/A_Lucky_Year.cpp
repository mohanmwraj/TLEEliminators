//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/808/A
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

void solve(){
    int n; cin >> n;

    int noOfDigits = 1;
    int firstDigit = n;

    while(firstDigit >= 10){
        noOfDigits++;
        firstDigit /= 10;
    }
    int ans = 0;
    if(firstDigit != 9){
        ans = (firstDigit + 1 ) * pow(10, noOfDigits - 1);// (10 ^ (noOfDigits - 1));
    } else {
        ans = 10 * pow(10,  noOfDigits - 1);
    }

    cout << ans - n << endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
