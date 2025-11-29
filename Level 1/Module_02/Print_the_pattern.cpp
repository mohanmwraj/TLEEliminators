//**********************************************************************************
// pbm : https://www.hackerearth.com/problem/golf/print-the-pattern/
//**********************************************************************************
/*
Given an integer n(1<=n<=10), print n rows of the given pattern in minimum length.

1

2 3

6 5 4

7 8 9 10

*/

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
	int current_value = 1;
	for(int i = 0; i < n; ++i){
        int a[i + 1];
        for(int j = 0; j < i + 1; ++j){
            a[j] = current_value++;
        }

        if(i % 2 == 0 ) reverse(a, a + (i + 1));

        for(int j = 0; j < i + 1; ++j){
            cout << a[j] << " ";
        }
        cout << endl;
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
