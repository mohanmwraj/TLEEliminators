//**********************************************************************************
// pbm : https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/c
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

    int even = 0, odd = 0, positive = 0, negative = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i] % 2 == 0){
            even++;
        } else { //if(arr[i] %2 != 0)
            odd++;
        } 

        if(arr[i] > 0){
            positive++;
        } else if(arr[i] < 0){
            negative++;
        }
    }

    cout<< "Even: " << even << endl;
    cout << "Odd: " << odd << endl;
    cout << "Positive: " << positive << endl;
    cout << "Negative: " << negative << endl;

}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
