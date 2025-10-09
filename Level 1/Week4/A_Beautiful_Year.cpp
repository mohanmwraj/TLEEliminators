//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/271/A
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

    // for(int i = n + 1; i < 10000; ++i){
    //     int freq[10];

    //     for(int j = 0; j < 10; ++j){
    //         freq[j] = 0;
    //     }
    //     //memset(freq, 0, sizeof(freq));

    //     int year = i;
    //     while(year > 0){
    //         int digit = year % 10;
    //         freq[digit]++;
    //         year /= 10;
    //     }
    //     int flag = 0;
    //     for(int j = 0; j < 10; ++j){
    //         if(freq[j] > 1) {
    //             flag = 1;
    //             break;
    //         }
    //     }

    //     if(flag == 0){
    //         cout << i << endl;
    //         break;
    //     }
    // }

    int a, b, c, d;
    while(true){
        n++;
        a = (n % 10);
        b = (n / 10) % 10;
        c = (n / 100) % 10;
        d = (n / 1000) % 10;

        if(a != b && a != c && a != d && b != c && b != d && c != d){
            break;
        }
    }

    cout << n << endl;
}

int main() {
    int T = 1;
   // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
