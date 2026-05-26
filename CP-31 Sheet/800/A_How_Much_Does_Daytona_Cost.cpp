//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1878/A
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
    subsegment or subarray is a contiguous part of an array. 
    For example, in the array [1, 2, 3, 4], the subsegments 
    include [1], [2], [3], [4], [1, 2], [2, 3], [3, 4], and [1, 2, 3], [2, 3, 4], and [1, 2, 3, 4].

     To determine if a number k is present in the array, 
     we can simply iterate through the array and check if any element is equal to k. 
     If we find such an element, we can immediately conclude that k is present in the array.

     if i take even 1-sized subsegment contains k, then it will be "YES" , because k will be present in that subsegment. and there
     is no condition given for length of the subsegment.
     So, we can just check if k is present in the array or not, and if it is present, 
     then we can say "YES", otherwise "NO".

     The algorithm can be implemented as follows:

    Check if k is present in the array or not. If present, print "YES", else print "NO".

    Time complexity: O(n) for each test case, where n is the size of the array.
    Space complexity: O(1) as we are using only a constant amount of extra space.

    n = 100. O(n) = 100 operations, which is efficient for our constraints.
*/


void solve(){
    ll n, k; cin >> n >> k;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    ll number_is_present = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == k){
            number_is_present = 1;
            break;
        }
    }

    if(number_is_present){
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
