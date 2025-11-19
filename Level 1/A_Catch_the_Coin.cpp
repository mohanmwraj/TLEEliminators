//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1989/A
//**********************************************************************************

/*

check the condition:

- for every step monocarp make, coins fall down one step (x, y - 1)
- means if the coins are greater < -1 in y axis means every step monocarp make, coins will fall back further, 
and can't able to collect the coin.

*/

#include<bits/stdc++.h>

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

void solve(){
    int x, y;
    cin >> x >> y;

    if(y < -1) {
        cout<<"NO"<<endl;
    }else {
        cout << "YES" <<endl;
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
