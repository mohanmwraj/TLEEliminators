//**********************************************************************************
// pbm : https://atcoder.jp/contests/abc244/tasks/abc244_b
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
    string s; cin >> s;

    int x = 0, y = 0;
    char dir = 'r';
    for(int i = 0; i < n; ++i){
        if(s[i] == 'S'){
            if(dir == 'r'){
                x++;
            } else if(dir == 'l'){
                x--;
            } else if(dir == 't'){
                y++;
            } else {
                y--;
            }
        } else {
            if(dir == 'r'){
                dir = 'd';
            } else if(dir == 'l'){
                dir = 't';
            } else if(dir == 't'){
                dir = 'r';
            } else {
                dir = 'l';
            }
        }
    }

    cout << x << " " << y << endl;
}

int main() {
    int T = 1;
   // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
