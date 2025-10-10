//**********************************************************************************
// pbm : https://atcoder.jp/contests/abc301/tasks/abc301_b
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

    for(int i = 0; i < n - 1; ++i){
        cout << arr[i] << " ";
        if(arr[i] > arr[i + 1]){
            int temp = arr[i] - 1;

            while(temp > arr[i + 1]){
                cout << temp << " ";
                temp--;
            }
        } else {
            int temp = arr[i] + 1;
            while(temp < arr[i + 1]){
                cout << temp << " ";
                temp++;
            }
        }
    }
    cout << arr[n - 1] << endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
