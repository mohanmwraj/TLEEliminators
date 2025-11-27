//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/919/B
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

int sumOfDigits(int n){
    int sum = 0;

    while(n){
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

void solve(){
    int n; cin >> n;

    int count = 0;
    for(int i = 19; i < 1100000000; i += 9){
        if(sumOfDigits(i) == 10){
            ++count;
            if(count == n){
                cout << i << endl;
                break;
            }
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
