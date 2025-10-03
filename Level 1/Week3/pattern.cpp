//**********************************************************************************
// pbm : https://www.hackerearth.com/problem/algorithm/pattern/
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

    for(int i = 0; i < n; ++i) cout<<'*';
    cout<<endl;

    for(int i = 0; i < n - 2; ++i){
        int noSpaces = (n - 2) - i;
        for(int j = 0; j < noSpaces; ++j)
            cout << " ";
        
        cout << '*' << endl;
    }

    for(int i = 0; i < n; ++i) cout<<'*';
    cout<<endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
