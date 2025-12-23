//**********************************************************************************
// pbm : https://codeforces.com/contest/1629/problem/B
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
    - Every no have prime factors
    - l, l + 1, l + 2 ... r => l(l+2), l + 1, r => gcd() > 1 ?
    - l, r, k: 3, 5, 1 => 

    After one operation a = [3, 4, 5]
    3, 20 | 12, 5 | 15, 4

    gcd ~ some common prime factors === GCD

    - we need to find the prime factor present in all the element.
    - so we need to choose the prime factor which is present in the maximum number of array elements.
    - even number have a prime factor 2, every alternate number in an array will have a prime factor of 2.
    - # of operations == # of numbers not containing that prime factor P.
    - Ex: P = 2, # Operaions = # of Odd numbers - all the odd numbers will not contain the prime factor 2.
    - 
*/

void solve(){
    ll l, r, k; cin >> l >> r >> k;

    if(l == r){
        if(l==1){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
        return;
    }

    int numOdd = (r - l + 1);
    if(numOdd % 2 == 1){
        numOdd /= 2;
        if(l%2 == 1 || r % 2 == 1){
            numOdd++;
        }
    } else {
        numOdd /= 2;
    }

    if(numOdd <= k){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
