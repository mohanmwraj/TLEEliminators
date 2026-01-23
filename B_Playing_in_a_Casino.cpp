//**********************************************************************************
// pbm : https://codeforces.com/contest/1808/problem/B
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
    after every game winner gets:
        let's say player i and j are playing
        abs(c[i][1] - c[j][1]) + abs(c[i][2] - c[j][2]) + ... + abs(c[i][m] - c[j][m])

    if(m > n) abs(m - n) = m - n
    else abs(m - n) = n - m

n = 3, m =  5
1 4 2 8 5 = c[0]
7 9 2 1 4 = c[1]
3 8 5 3 1 = c[2]

total games => (0, 1), (0, 2), (1, 2)

(0, 1)
total winnings = |1 - 7| + |4 - 9| + |2 - 2| + |8 - 1| + |5 - 4| = 6 + 5 + 0 + 7 + 1 = 19

(0, 2)
total winnings = |1 - 3| + |4 - 8| + |2 - 5| + |8 - 3| + |5 - 1| = 2 + 4 + 3 + 5 + 4 = 18   

(1, 2)
total winnings = |7 - 3| + |9 - 8| + |2 - 5| + |1 - 3| + |4 - 1| = 4 + 1 + 3 + 2 + 3 = 13

final winnings: 19 + 18 + 13 = 50
player 0 = 19 + 18 = 37
player 1 = 19 + 13 = 32
player 2 = 18 + 13 = 31

*/

void solve(){
    
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
