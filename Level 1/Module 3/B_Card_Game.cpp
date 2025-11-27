//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1999/B
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
    int a, b, c, d; 
    cin >> a >> b >> c >> d;

    if(a > c && b > d && a > d && b > c){
        cout << "4" << endl;
    } else if(((a > c && b >= d) || (a >= c && b > d)) 
            && ((a > d && b >= c) || (a >= d && b > c))){
                cout << "4" << endl;
   } else if ((a > c && b >= d) || (a >= c && b > d) ||
       (a > d && b >= c) || (a >= d && b > c)){
            cout << "2" << endl;
        } else {
            cout << "0" << endl;
        }

}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
