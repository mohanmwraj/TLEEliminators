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
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j <= rows - i - 1; ++j){
            cout << "*";
        }
        cout << endl;
    }
}

/*
output:
*****
****
***
**
*

*/

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
