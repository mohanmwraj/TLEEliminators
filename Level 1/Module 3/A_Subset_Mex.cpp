//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1406/A
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
    
    int arr[n + 1]; int count[101];
    for(int i = 0; i < 101; ++i) count[i] = 0;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        count[arr[i]]++;
    } 

    int mexa = 0;
    while(count[mexa] >= 1) mexa++;

    int mexb = 0;
    while(count[mexb] >= 2) mexb++;

    cout << mexa + mexb << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
