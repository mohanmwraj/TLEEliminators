//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1896/A
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
    if a[0] = 1, then the permutation can be sorted, otherwise it is impossible.

    Select an index i from 2 to n-1 such that a[i-1] < a[i] and a[i] > a[i+1], and then
    Swap a[i] and a[i+1].

    if you pick up largest number, it will always satisfy the condition a[i-1] < a[i] and a[i] > a[i+1], 
    and you can swap it with the next element to move it to the end of the array.

    1 4 5 2 3
    1 4 2 5 3
    1 4 2 3 5
    1 2 4 3 5
    1 2 3 4 5

    Time Complexity: O(1) as we are just checking the first element of the array.
    Space Complexity: O(1)

    Missed:
    Permuation first number should be 1, otherwise it is impossible to sort the array using the given operation.
    
*/

void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }

    if(a[0] == 1){
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
