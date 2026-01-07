//**********************************************************************************
// pbm : https://leetcode.com/problems/isomorphic-strings/description/
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

void solve(string s, string t){
    // string s, t;
    // cin >> s >> t;

    if(s.length() != t.length()){
        cout << "false" << endl;
        return;
    }

    unordered_map<char, char> sToT;
    unordered_map<char, char> tToS;

    for(int i = 0; i < s.length(); i++){
        char sc = s[i];
        char tc = t[i];

        // check mapping from s to t
        if(sToT.find(sc) != sToT.end()){
            if(sToT[sc] != tc){
                cout << "false" << endl;
                return;
            }
        } else {
            sToT[sc] = tc;
        }

        // check mapping from t to s
        if(tToS.find(tc) != tToS.end()){
            if(tToS[tc] != sc){
                cout << "false" << endl;
                return;
            }
        } else {
            tToS[tc] = sc;
        }
    }
    cout << "true" << endl;
}

void map_with_int_Value(string s, string t){
    if(s.length() != t.length()){
        cout << "false" << endl;
        return;
    }

    unordered_map<char, int> sMap;
    unordered_map<char, int> tMap;

/*
    paper = 'p' - 0
    title = 't' - 0 

    p == t == 0

    map<char, int> sMap;
    map<char, int> tMap;

    for(int i = 0; i < s.size(); i++){
        if(sMap[s[i]] != tMap[t[i]]){
            return false;
        }
        sMap[s[i]] = i + 1;
        tMap[t[i]] = i + 1;
    }


*/

    for(int i = 0; i < s.length(); i++){
        char sc = s[i];
        char tc = t[i];

        if(sMap.find(sc) == sMap.end()){
            sMap[sc] = i;
        }

        if(tMap.find(tc) == tMap.end()){
            tMap[tc] = i;
        }

        if(sMap[sc] != tMap[tc]){
            cout << "false" << endl;
            return;
        }
    }
    cout << "true" << endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve("egg", "add");
    }
    return 0;
}
