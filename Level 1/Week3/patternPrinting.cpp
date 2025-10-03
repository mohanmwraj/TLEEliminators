//**********************************************************************************
// pbm : https://www.geeksforgeeks.org/problems/pattern-printing1347/1
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
        
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < i; ++j){
                cout <<'*';
            }
            cout << ' ';
        }
        //cout << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
/*
Input:
N = 5
Output:
* ** *** **** ***** 
Explanation:
First, print 1 asterisk then space after
that print 2 asterisk and space and do this
3 more times.
*/