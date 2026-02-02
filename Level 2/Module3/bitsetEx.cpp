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

void solve(){
    
    bitset<40> b1;
    bitset<40> b2;

    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        b1[x] = 1;
    }

    for(int i = 0; i < m; i++){
        int x; cin >> x;
        b2[x] = 1;
    }

    bitset<40> andBitset = b1 & b2; // intersection
    bitset<40> orBitset = b1 | b2;  // union
    bitset<40> xorBitset = b1 ^ b2; // symmetric difference

    cout << "AND Bitset: " << andBitset << endl;
    cout << "OR Bitset: " << orBitset << endl;
    cout << "XOR Bitset: " << xorBitset << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
