//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1705/B
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
    int arr[n + 1]; // +1 because of 1 based indexing.
    for(int i = 1; i <= n; ++i ) cin >> arr[i];

    ll cntz = 0;
    ll sum = 0;
    bool flag = false;

    for(int i = 1; i <= n - 1; ++i){
        sum += arr[i];

        // 0 0 3 3 1 
        // flag is used to count zeros after encountering first positive integer
        // and not to consider leading zeros
        if(arr[i] > 0) flag = true;
        if(arr[i] == 0 && flag == true) cntz++;
    }

    cout << sum + cntz << endl;


}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
