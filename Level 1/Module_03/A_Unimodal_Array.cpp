//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/831/A
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
    
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];

    // bool inc = false, cnst = false, decr = false;

    // for(int i = 0; i < n; ++i){
    //     if(i > 0 && arr[i - 1] < arr[i]){
    //         inc = true;
    //     }

    //     if(i > 0 && arr[i - 1] == arr[i]){
    //         cnst = true;
    //     }

    //     if(i > 0 && arr[i - 1] > arr[i]){
    //         decr = true;
    //     }
    // }

    // if((inc & cnst & decr) || (cnst) ){
    //     cout << "YES" << endl;
    // } else if((inc & decr) && (n % 2 != 0)){
    //     cout << "YES" << endl;
    // } else {
    //     cout << "NO" << endl;
    // }

    int pos1 = 0, pos2 = n - 1;

    for(int i = 0; i < n - 1; ++i){
        if(arr[i] < arr[i + 1]){
            pos1++;
        } else {
            break;
        }
    }

    for(int i = n - 1; i > 0; --i){
        if(arr[i] < arr[i - 1]){
            pos2--;
        } else {
            break;
        }
    }

    int ele = arr[pos1];
    bool flag = true;

    for(int i = pos1; i <= pos2; ++i){
        if(arr[i] != ele){
            flag = false;
        }
    }

    if(flag) {
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
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
