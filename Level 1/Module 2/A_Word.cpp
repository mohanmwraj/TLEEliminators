//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/59/A
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
    string s; cin >> s;

    int n = s.size();
    int lowercase = 0, uppercase = 0;

    for(int i = 0; i < n; ++i){
        if(s[i] >= 'a' && s[i] <= 'z'){
            lowercase++;
        } else {
            uppercase++;
        }
    }

    if(lowercase >= uppercase){
        for(int i = 0; i < n; ++i){
            s[i] = tolower(s[i]);
        }
        cout << s << endl;
    } else {
        for(int i = 0; i < n; ++i){
            s[i] = toupper(s[i]);
        }
        cout << s << endl;
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
