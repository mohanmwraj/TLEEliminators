//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1900/A
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
    If three consecutive '.', use 2 actions, else count '.' for actions needed.

*/

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    bool continuous_three_empty_cells = false;
    int total_count_of_empty_cells = 0;

    for(int i = 0; i < n; i++){

        if(s[i] == '.' && i >= 2 && s[i - 1] == '.' && s[i - 2] == '.'){
            continuous_three_empty_cells = true;
        }

        if(s[i] == '.'){
            total_count_of_empty_cells++;
            // if(i >= 2 && s[i - 1] == '.' && s[i - 2] == '.'){
            //     continuous_three_empty_cells = true;
            // }
        }
    }

    if(continuous_three_empty_cells){
        cout << 2 << endl;
    } else {
        cout << total_count_of_empty_cells << endl;
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
