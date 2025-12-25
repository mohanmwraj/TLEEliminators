//**********************************************************************************
// pbm : https://www.spoj.com/problems/FACT0/
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
    
    Given a number N (up to 15 digits), we need to find its prime factorization.
    Since N can be very large (up to 10^15), we need to use efficient algorithms to factor it.

    We can use trial division up to the square root of N to find small prime factors.
    For larger factors, we can use Pollard's Rho algorithm or other advanced factorization methods.

    Steps:
    1. Check for divisibility by small primes (2, 3, 5, 7, 11, ...).
    2. If N is still greater than 1 after removing small prime factors, use Pollard's Rho or similar methods.
    3. Collect and print the prime factors.

*/

void solve(){

}

int main() {
    // int T = 1;
    // //cin >> T;
    // while(T--){
    //     solve();
    // }

    long long n = -1; 
    while(n!= 0){
        cin >> n;
        if(n == 0) break;

        map<ll, ll> prime_factors;
        while(n%2 == 0){
            prime_factors[2]++;
            n /= 2;
        }

        for(ll i = 3; i * i <= n; i += 2){
            while(n % i == 0){
                prime_factors[i]++;
                n /= i;
            }
        }

        if(n > 2){
            prime_factors[n]++;
        }
        
        for(auto it: prime_factors){
            cout << it.first << "^" << it.second << " ";
        }
        cout << endl;
    }
    return 0;
}
