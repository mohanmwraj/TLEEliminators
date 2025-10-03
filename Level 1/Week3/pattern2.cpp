//**********************************************************************************
// pbm : https://www.geeksforgeeks.org/problems/pattern/1
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
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n - i - 1; ++j){
                cout << " ";
            }
            
            for(int j = 0; j < i + 1; ++j){
                cout << "* ";
            }
            
            cout << endl;
        }
        
        for(int i = n - 1; i >= 0; --i){
            for(int j = 0; j < n - i - 1; ++j){
                cout << " ";
            }
            
            for(int j = 0; j < i + 1; ++j){
                cout << "* ";
            }
            
            cout << endl;
        }    
}

int main() {
    int T = 1;
   // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
