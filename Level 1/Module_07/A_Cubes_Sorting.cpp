//**********************************************************************************
// pbm : https://codeforces.com/contest/1420/problem/A
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
    Any array with non - unique elements and in decresing order, then operation needs to be sorted is < n(n-1)/2 - 1.
    Any permutation of an array with duplicate elements can be also sorted in less than n(n-1)/2 - 1 operations.

    For the above two cases, answer is always YES.

    For an array with all unique elements in decreasing order, it needs exactly n(n-1)/2 operations to be sorted.
    So, for this case, answer is NO.

    No - if array is sorted in strictly decreasing order with all unique elements.
    Yes - otherwise. Any array given which does satisy the above condition can be sorted in less than n(n-1)/2 - 1 operations.

*/


void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    bool flag = true;
    for(int i = 0; i < n - 1; ++i){
        if(arr[i] <= arr[i + 1]){ // if this is true => not strictly decreasing or array has duplicate elements.
            flag = false;
            break;
        }
    }

    if(flag){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
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
