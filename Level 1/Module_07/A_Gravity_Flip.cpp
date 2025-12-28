//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/405/A
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
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
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
