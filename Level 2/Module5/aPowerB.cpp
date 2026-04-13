//**********************************************************************************
// pbm : 
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
    Given two numbers and b, calculate a^b.

*/

int power(int a, int b){
    if(b== 0) return 1;

    return a * power(a, b-1);
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        int a, b;
        cin >> a >> b;
        cout << power(a, b) << endl;
    }
    return 0;
}
