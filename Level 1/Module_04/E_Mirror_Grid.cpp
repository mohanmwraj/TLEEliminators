//**********************************************************************************
// pbm : https://codeforces.com/contest/1703/problem/E
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
                        c1 - (i, j)
90 degree rotation      c2 - (j, n - i - 1)
180 degree rotation     c3 - (n - i - 1, n - j - 1)
270 degree rotation     c4 - (n - j - 1, i)
*/

void solve(){
    int n; cin >> n;
    string mat[n];
    for(int i = 0; i < n; ++i){
        cin >> mat[i];
    }

    int x = n / 2, y = n / 2;
    if(n % 2 == 1){
        y++;
    }

    int ans = 0;
    for(int i = 0; i < x; ++i){
        for(int j = 0; j < y; ++j){
            int ones = 0;
            ones += mat[i][j] - '0';
            ones += mat[j][n - i - 1] - '0';
            ones += mat[n - i - 1][n - j - 1] - '0';
            ones += mat[n - j - 1][i] - '0';

            if(ones == 2){
                ans += 2;
            } else if (ones == 1 || ones == 3){
                ans += 1;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
