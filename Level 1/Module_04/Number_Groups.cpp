//**********************************************************************************
// pbm : https://www.hackerrank.com/challenges/number-groups/problem
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
    AP = (n/2)(2a + (n-1)d)
    before kth group, k-1 gropup already complete
    1, 2, 3, ..... (k-1), k
    d - common difference = 1;
    a - starting element = 1;

    ((k-1)/2)(2(1) + ((k-1)-1)1) -> (k-1)(k)/2 

    kth start from next number of (k-1)k/2 upto to k nnumbers
    (k-1)k/2 + k => ((k-1)k + 2k)/2 => k(k+1)/2
*/

void solve(){
    ll k; cin >> k;

    cout << k * k * k << endl;

}

int main() {
    int T = 1;
   // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
