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
        for(int j = 0; j < rows; ++j){
            if(i > 0 && i < rows - 1 && j > 0 && j < rows - 1){
                cout << " ";
            } else {
                cout << "*";
            }
        }
        cout << endl;
    }
}
/*
output:

*****
*   *
*   *
*   *
*****

*/
int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
