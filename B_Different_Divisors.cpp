//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1474/B
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
    Number a, divisors of a are d1, d2, d3, ..., dk == c >= 4. Atleast 4 different divisors.

    d1, d2, d3, d4 are different divisors of a. => abs(di - dj) >= d

    we need to find a smallest a such that a has at least 4 different divisors and
    for any two different divisors di and dj, abs(di - dj) >= d.

    ex: d = 2, ans = 15. 1, 3, 5, 15 are divisors of 15. all divisors differ by at least 2.

    N a composite number.
    can be expressed as a product of primes.
    a = p1^a1 * p2^a2 * p3^a3 ... pk^ak
    number of divisors of a = (a1 + 1) * (a2 + 1) * ... * (ak + 1) >= 4

    N = 2^3 * 3^2 * 5^1 => permutations of exponents (3, 2, 1)
    number of divisors = (3 + 1) * (2 + 1) * (1 + 1) = 4 * 3 * 2 = 24

    number of divisors of a = (a1 + 1) * (a2 + 1) * ... * (ak + 1) >= 4
    To have at least 4 divisors, we have two cases:
    1. k >= 2 (atleast two distinct prime factors)
        -> (a1 + 1) * (a2 + 1) >= 4
        -> minimum when a1 = 1, a2 = 1
        -> number of divisors = 4
    2. k = 1 (only one prime factor)
        -> (a1 + 1) >= 4
        -> minimum when a1 = 3
        -> number of divisors = 4

    4 different divisors can be achieved in two ways: 1 * 4 or 2 * 2
    1. 1 * 4 => k = 1, a1 = 3 => a = p1^3
    2. 2 * 2 => k = 2, a1 = 1, a2 = 1 => a = p1^1 * p2^1    

    Operation 1 -> 1 * 4 => (a1 + 1) * (a2 + 1) 
            = (a1 + 1) = 1 => a1 = 0
            = (a2 + 1) = 4 => a2 = 3
            = N = p1^3 (prime number raised to power 3)

    Operation 2 -> 2 * 2 => (a1 + 1) * (a2 + 1)
            = (a1 + 1) = 2 => a1 = 1
            = (a2 + 1) = 2 => a2 = 1
            = N = p1^1 * p2^1 (two distinct prime numbers raised to power 1)

    N has to look like one of the above two forms to have at least 4 different divisors.

    Case 1 => p^3 where p >= 2
    ----------------------------
    1 < p < p1 < p2 < ... < pk

    d1 = p - 1, d2 = p1 - p, d3 = p2 - p1
    where d1, d2, d3 >= d

    p -1 >= d
    p2 - p1 >= d
    p1 - p >= d
    From above inequalities, we can say that:
    p - 1 >= d
    p(p - 1) >= d
    p2(p - 1) >= d

    if one case is truem then all other cases will be true.

    p = 3

    1 3 9 27 => 1 p p^2 p^3

    p - 1 = 2 >= 2
    p^2 - p = 6 >= 2
    p^3 - p^2 = 18 >= 2

    we want the prime value p which has this condition true i.e., p - 1 >= d or p >= d + 1

    case 2: p1 * p2 where p1 and p2 are distinct primes
    ----------------------------------------------
    1 < p1 < p2
    d1 = p1 - 1, d2 = p2 - p1, d3 = p1 * p2 - p2
    where d1, d2, d3 >= d   
    1 p q pq (p < q) (p >= 2) (q >= 2)
    from above inequalities, we can say that:

    p - 1 >= d -> p - 1 >= d
    q - p >= d -> q - p >= d
    pq - q >= d -> q(p - 1) >= d

    case 2 want another prime q such that q - p >= d and q(p - 1) >= d.

    Case 1: k >= 2
        a = p1^1 * p2^1 => number of divisors = 4
        to minimize a, choose smallest primes.
        p1 = 2, p2 = 3 => a = 6
        divisors = 1, 2, 3, 6. all differ by at least 2.
    Case 2: k = 1
        a = p1^3 => number of divisors = 4
        to minimize a, choose smallest prime.
        p1 = 2 => a = 8
        divisors = 1, 2, 4, 8. all differ by at least 2.

*/

vector<ll> primes;

void solve(){
    ll d; cin >> d;

    ll p = *lower_bound(primes.begin(), primes.end(), d + 1);
    ll q = *lower_bound(primes.begin(), primes.end(), p + d);   

    ll a = min(1ll * p * q, 1ll * p * p * p);
    cout << a << endl;
}

int main() {
    int T = 1;
    cin >> T;

    for(ll i = 2; i <= 100000; i++){
        bool isPrime = true;
        for(ll j = 2; j * j <= i; j++){
            if(i % j == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            primes.push_back(i);
        }
    }

    while(T--){
        solve();
    }
    return 0;
}
