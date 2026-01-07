//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1765/M
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
    Given N, find the a and b, such that a > 0, b > 0
    a + b = N,
    LCM(a, b) is minimum.

    1. symmetry is repeating after N/2.
    so we can just assume a <= b.
    so if a <= b, then b >= N/2.

    2. a <= b

    b % a == 0 (case 1)

    LCM(a, b) = b

    a = p1^a1 * p2^a2 * p3^a3 * ... * pk^ak
    b = p1^b1 * p2^b2 * p3^b3 * ... * pk^bk

    LCM(a, b) = p1^max(a1, b1) * p2^max(a2, b2) * p3^max(a3, b3) * ... * pk^max(ak, bk)
    sinve b is greater than or equal to a,
    LCM(a, b) = b

    b >= N/2 so b < N, therefore LCM(a, b) < N.

    b % a != 0 (case 2)

    LCM(a, b) > b >= N/2 ==> LCM(a, b) >= 2 * b

    means there are some prime factors in a which are not in b.
    therefore LCM(a, b) will have those prime factors too.
    therefore LCM(a, b) > b >= N/2.

    a <= b
    b%a == 0 -> more close to my answer.

    lcm(a, b) == b
    n % a == 0

    a + b == n
    (a + b) % a = n % a ==> (a%a + b % a) % a = n % a
    a%a == 0
    b % a = 0
    (0 + 0) % a = n % a
    0 = n % a
    n % a == 0


    Three observations
    1. a <= b
    2. b % a == 0
    3. n % a == 0

    for(factors of n to find a){
        a = factor
        b = n - a
        if(b % a == 0){
            lcm(a, b) = b
            update ans
        }
    }
*/

void solve(){
    ll k; cin >> k;
    ll a = 1;
    for(ll fac = 2; fac * fac <= k; ++fac){
        if(k % fac == 0){
            a = k / fac;
            break;
        }
    }
    cout << a << " " << k - a << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
