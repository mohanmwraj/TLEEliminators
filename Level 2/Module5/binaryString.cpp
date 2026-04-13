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
    Generate binary string for number n.
*/

void solve(int n){
    string binary = bitset<32>(n).to_string();
    binary.erase(0, binary.find_first_not_of('0'));
    cout << binary << endl;
}

string binaryRepresentation(int n){
    if(n == 0) return "";
    string ans = binaryRepresentation(n/2);

    if(n%2 == 0){
        ans += '0';
    } else {
        ans += '1';
    }
    return ans;
}

string binString(int n){
    if(n < 2){
        return to_string(n);
    }
    string ans = binString(n/2);
    int rem = n%2;
    ans += to_string(rem);
    return ans;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        int n; cin >> n;
        solve(n);
    }
    return 0;
}
