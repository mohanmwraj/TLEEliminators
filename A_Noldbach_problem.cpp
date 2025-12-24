//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/17/A
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
    int n, k; cin >> n >> k;

    vector<int> primes;
    for(int i = 2; i <= n; ++i){
        int count = 0;
        for(int j = 1; j * j <= i; ++j){
            if(i % j == 0){
                count++;
                if(i/j != j){
                    count++;
                }
            }
        }
        // If the number have only two divisors then it is prime. We are pushing into prime vector.
        if(count == 2){
            primes.push_back(i);
        }
    }

    int ans = 0;
    int m = primes.size();

    for(int i = 0; i < m - 1; ++i){
        int temp = primes[i] + primes[i+1] + 1;
        bool flag = false;
        for(int j = 0; j < m; ++j){
            if(primes[j] == temp){
                flag = true;
                break;
            }
        }

        if(flag == true){
            ans++;
        }
    }
    if(ans >= k) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
