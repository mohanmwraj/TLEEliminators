//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/898/B
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
    x.a + y.b = n

    brute force 10^7 * 10^ 7 == n^2 == 10^14 > 10^8 TLE
    -----------
    for(x: 0 to n){
        for(y: 0 to n){
            if(x*a + y*b == n){
                print YES
            }
        }
    }

    -----------------------
    x.a + y.b = n

    x = n - y.b / a 

    x,y E z+ ==> x and y must be positive integers.

    x: 0 to n ==> y E z+
    y: 0 to n ==> x E z+

    for(y: 0 to n){
        x = n - y.b /a

        if(x E z+){
            print X,Y
            print "YES"
            return
        }
    }


    To check x E z+

    x >= 0 && (n - yb) % a == 0
*/

void solve(){
    ll n, a, b;
    cin >> n >> a >> b;

    ll x = -1, y;

    for(y = 0; y <= 1e7; ++y){
        if((n - y * b) % a == 0 && (n - y * b >= 0)){
            x = (n - y * b) / a;
            break;
        }
    }

    if(x == -1){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << x << " " << y << endl;
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
