//**********************************************************************************
// pbm : https://atcoder.jp/contests/abc242/tasks/abc242_b
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
    int arr[26];

    memset(arr, 0, sizeof(arr));
    for(int i = 0; i < n; ++i){
        arr[s[i] - 'a']++;
    }

    string ans = "";
    for(int i = 0; i < 26; ++i){
        char c = i + 'a';
        while(arr[i] > 0){
            ans += c;
            arr[i]--;
        }
    }

    cout << ans << endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
