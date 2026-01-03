//**********************************************************************************
// pbm : https://codeforces.com/contest/1174/problem/A
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
You're given an array 𝑎 of length 2𝑛. Is it possible to reorder it in such way 
so that the sum of the first 𝑛 elements isn't equal to the sum of the last 𝑛 elements?

Partition the array and sort one half in ascending order and the other half in descending order.

Two cases

Case 1: "-1"
Case 2: form a reordering such that first N != last N

Case 1: if all elements are the same, then it's impossible to form such a reordering. 

a1, a2, a3, a4. => a1 + a2 == a3 + a4 => a1 = a2 = a3 = a4 = 2.
if a4 != 2, 2 2 2 3 => 2 + 2 != 2 + 3

Case 2: first N != last N

-> greedy place smaller elements in the first half and larger elements in the second half.
-> sort the array will give the answer

2 1 3 2 1 3 => sort => 1 1 2 2 3 3 => first half = 1 1 2, second half = 2 3 3 => 1 + 1 + 2 != 2 + 3 + 3

*/

void solve(){
    int n; cin >> n;
    n *= 2;

    vector<ll> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    ll firstN = 0, lastN = 0;
    for (size_t i = 0; i < n/2; i++)
    {
        firstN += arr[i];       
        lastN += arr[i + n/2];
    }
    if(firstN == lastN){
        cout << -1 << endl;
    }
    else{
        for (size_t i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
