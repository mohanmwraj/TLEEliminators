//**********************************************************************************
// pbm : https://atcoder.jp/contests/jsc2021/tasks/jsc2021_c
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
    - no must divide both x and y and maximum value of y can be b.
    - if no divides x and y, g must be less than or equal to both x and y.
    - In the range [1, N], the number of integers divisible by x are floor(N/x).

    Because gcd(x, y) = c implies both x and y are multiples of c, and 
    conversely if the interval [A, B] contains at least two multiples of c (kc and (k+1)c) 
    then gcd(kc, (k+1)c) = c, so a pair (x, y) with gcd c exists.

    since B <= 2 * 10^5, for each c, one can check if the segment [A, B] contains at least two multiples of c, 
    so that original problem is solved fast enough.

    The number of multiples of c in [A, B] 
                = the number of multiples of c in [1, B] - the number of multiples of c in [1, A-1]
                is given by floor(B/c) - floor((A-1)/c).
    otherwise, since it is suffice to check if there are at least two multiples of c in [A, B],
    we can check it by [A/C] < [B/C]
*/

void solve(){
    int a, b; cin >> a >> b;
    for(int c = b; c >= 1; --c){
        // if( (b / c) - ( (a - 1) / c) >= 2 )
        if( (a + c - 1) / c < b / c ){
            cout << c << endl;
            return;
        }
    }

}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
