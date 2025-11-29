//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1800/A
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
    ll n; cin >> n;
    string s; cin >> s;

    string s1 = "";
    string s2 = "meow";

    if(n < 4){
        cout << "NO" << endl;
        return;
    }

    for(int i = 0; i < n; ++i){
        char c = (tolower(s[i]));
        s1 += c;
    }

    int a = -1, b = -1, c = -1, d = -1;
    int i = 0;

    if(s1[i] == 'm'){
        while(s1[i] == 'm' && i < n){
            a = 1; i++;
        }
    } else {
        cout << "NO" << endl;
        return;
    }

    if(s1[i] == 'e'){
        while(s1[i] == 'e' && i < n){
            b = 1; i++;
        }
    } else {
        cout << "NO" << endl;
        return;
    }

    if(s1[i] == 'o'){
        while(s1[i] == 'o' && i < n){
            c = 1; i++;
        }
    } else {
        cout << "NO" << endl;
        return;
    }

    if(s1[i] == 'w'){
        while(s1[i] == 'w' && i < n){
            d = 1; i++;
        }
    } else {
        cout << "NO" << endl;
        return;
    }

    if(a == 1 && b == 1 && c == 1 && d == 1 and i == n){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
