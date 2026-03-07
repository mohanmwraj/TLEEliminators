//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/579/A
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

/*

   Doubling a number shifts its bits to the left by one position.

    5 - 101
    1 (put a bacteria)
    10 (double)
    101 (double)
    101 (put a bacteria) = 5

    no of time i put a bacteria  = no of set bits in binary representation of x

    Ans = calculate the number of set bits in x
*/

void solve(){
    int x; cin >> x;
    int cnt_bits = 0;

    for(int i = 0; i < 31; i++){
        if(x & (1 << i)){
            cnt_bits++;
        }
    }
    cout << cnt_bits << endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
