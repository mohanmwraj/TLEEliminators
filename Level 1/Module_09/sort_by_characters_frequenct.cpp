//**********************************************************************************
// pbm : https://leetcode.com/problems/sort-characters-by-frequency/description/
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
#include <map>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

/*

Given a string s, sort it in decreasing order based on the frequency of the characters. 
The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

*/

void solve(){
    string s; cin >> s;
    vector<pair<int, char>> v;
    map<char, int> mp;
    for(int i = 0; i < s.size(); ++i){
        mp[s[i]]++;
    }
    for(auto it : mp){
        v.push_back({it.second, it.first});
    }
    sort(v.rbegin(), v.rend());
    string ans = "";
    for(int i = 0; i < v.size(); ++i){
        for(int j = 0; j < v[i].first; ++j){
            ans += v[i].second;
        }
    }
    cout << ans << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
