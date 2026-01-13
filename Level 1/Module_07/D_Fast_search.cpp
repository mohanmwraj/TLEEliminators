//**********************************************************************************
// pbm : https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D
//**********************************************************************************
#include "bits/stdc++.h"

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

/*
    No of numbers that are <= l - 1 == ans1
    No of numbers that are <= r == ans2
    ans2 - ans1 == no of numbers in range [l, r]

Time Complexity: n + n log n + k (2 log n)
=> O((n + k) log n )
Space Complexity: O(n)
*/

int helper(int x, int n, int a[]){
    int low = 0, high = n - 1;
    int ans = -1;
    while(low <= high){
        int mid = (high + low) / 2;
        if(a[mid] <= x){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans + 1; // +1 for count
}


void solve(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    int k; cin >> k;
    for(int i = 0; i < k; ++i){
        int l, r; cin >> l >> r;
        int ans1 = helper(l - 1, n, a);
        int ans2 = helper(r, n, a);
        cout << ans2 - ans1 << " ";
    }

}

int main() {
    int T = 1;
   // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
