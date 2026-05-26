//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1890/A
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
#include <map>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

/*
    condition: a[i -1] + [ai] == a[i] + a[i + 1] .... a[n-1] + a[n] == k.

    a[i -1] + [ai] == a[i] + a[i + 1] 

        a[i -1] + [ai] == a[i] + a[i + 1]
        a[i - 1] = a[i + 1] => odd index should have same number, 
        similarly a[i] = a[i + 2] => even index should have same number.

    Check the ferquency of distinct numbers. Consider odd/Even length cases.

    Case 1: if there are 3 or more distinct numbers, then we cannot make all elements equal, so the answer is "No".
    Case 2: if there are 2 distinct numbers, then we can make all elements equal if the frequency of both numbers is the same, or if the frequency of one number is one more than the other (in case of odd length). Otherwise, the answer is "No".
    Case 3: if there is only 1 distinct number, then we can make all elements equal, so the answer is "Yes".


    Time complexity: O(n long n) due to map insertion and lookup.
    Space complexity: O(n) in the worst case when all elements are distinct.

    n = 100. O(n log n) = 100 * log(100) = 100 * 6.64 = 664 operations, which is efficient for our constraints.
*/


void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    map<ll, ll> frequency_map;
    for(int i = 0; i < n; i++){
        frequency_map[a[i]]++;
    }

    if(frequency_map.size() >= 3){
        cout<< "No" << endl;
    } else {
        ll freq1 = frequency_map.begin()->second;
        ll freq2 = frequency_map.rbegin()->second;

        if(freq1 == freq2){ //freq1 == freq2 == 1 when there are 1 distinct number.
            cout << "Yes" << endl;
        } else if(n % 2 == 1 && abs(freq1 - freq2) == 1){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
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
