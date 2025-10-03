//**********************************************************************************
// pbm : https://codeforces.com/group/MWSDmqGsZm/contest/326175/problem/D
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
    ll a, b, c, d;
    //ll d;
    cin >> a >> b >> c >> d;

    string output = "NO";

    if(a + b - c == d) output = "YES";
    if(a + b * c == d) output = "YES";
    if(a - b + c == d) output = "YES";
    if(a - b * c == d) output = "YES";
    if(a * b + c == d) output = "YES";
    if(a * b - c == d) output = "YES";

    cout << output << endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}

/*
Test Case 7: Overflow if we use int
Input
-432300451 509430974 -600857890 -220227239212711384
Output
NO
Answer
YES
Checker Log
wrong answer 1st lines differ - expected: 'YES', found: 'NO'

*/