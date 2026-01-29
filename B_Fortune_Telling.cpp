//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1634/B
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
    Alice -> x
    Bob -> x + 3. either one of the them will reach y.

    a1 a2 a3 a4 ... an

    Obs1: Parity of numbers that Alice and bob are starting with are different.

    3 + 5 = 8 | 3 ^ 5 = 6

    3 ^ 4 = 7 | 3 + 4 = 7

    Obs2: If + and ^ on odd numbers the parity changes.
          If + and ^ on even numbers the parity remains same.

    if x is even:
        y is even -> Alice
        y is odd  -> Bob
    
    if x is odd:
        y is even -> Bob
        y is odd  -> Alice

    
*/


void solve(){
    ll n, x, y; 
    cin >> n >> x >> y;

    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    ll f = 1; // f == 0 is odd
    for(int i = 0; i < n; i++){
        if(arr[i] & 1){
            f = (!f); //
        }
    }

    // If we start with odd number we end at the number same as parity of f
    // If we start with even number we end at the number opposite to parity of f
    if(x & 1){
        // if((f & 1) && (y & 1)){
        if(!((f ^ y) & 1LL)){
            cout << "Alice" << endl;
        // } else if(!(f & 1) && !(y & 1)){
        //     cout << "Alice" << endl;
        // } 
        } else {
            cout << "Bob" << endl;
        }
    } else {
        //if(((f & 1)) && (y & 1)){
        if(!((f ^ y) & 1LL)){
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
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
