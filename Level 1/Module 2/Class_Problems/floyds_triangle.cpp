//**********************************************************************************
// pbm : 
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
    int rows = 5;
    int n = 1;

    for(int i = 0; i < rows; ++i){
        for(int j = 0; j <= i; ++j){
            cout << n++;
        }
        cout << endl;
    }
}

/*
output:
1
23
456
78910
1112131415
*/

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
