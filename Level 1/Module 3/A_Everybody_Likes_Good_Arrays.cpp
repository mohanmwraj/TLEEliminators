//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1777/A
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

    // int arr[n];
    // for(int i = 0; i < n; ++i) cin >> arr[i];

    vector<int> a(n);
    for(int &it: a) cin >> it;

    int k = 0, totalOps = 0;
    for(int i = 0; i < n; ++i){
        if(i == 0 || a[i - 1] % 2 == a[i] % 2){
            k++;
        } else {
            totalOps += k - 1;
            k = 1;
        }
    }

    totalOps += k - 1;
    cout << totalOps << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
