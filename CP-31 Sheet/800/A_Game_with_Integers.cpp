//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1899/A
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
    if n % 3 == 0, Vova wins ('Second')
    else vanya wins ('First')

    This checks if Vanya can make n divisible by 3 immediately.

    Both players play optimally, means both player plays to win.

    Mistake:
        Missed the condition for each step player can add 1 or subtract 1 from n. 
        Read the question properly and remember the constraints.

    Time complexity: O(1) for each test case, as we are just checking the condition n % 3 == 0.
    Space complexity: O(1) as we are using only a constant amount of space.
*/

void solve(){
    int n; cin >> n;

    // for(int i = 0; i < 20; ++i){
    //     n += 1;
    //     if(i % 2 == 0 && n % 3 == 0){
    //         cout << "First" << endl;
    //         return;
    //     }
    // }
    // cout << "Second" << endl;

    if(n % 3 == 0){
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
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
