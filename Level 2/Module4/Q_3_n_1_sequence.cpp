//**********************************************************************************
// pbm : https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/Q
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
    Given a number n, print the length of the 3n + 1 sequence starting from n.

    Sequence rules:
    - If n is odd, the next number is 3 * n + 1.
    - If n is even, the next number is n / 2.
    
    For example, the 3𝑛+1 sequence of 3 is {3,10,5,16,8,4,2,1} and its length is 8.
*/

// int main() {
//     long long n;
//     cin >> n;
    
//     long long count = 0;
//     while (n != 1) {
//         if (n % 2 == 1) {
//             n = 3 * n + 1;
//         } else {
//             n = n / 2;
//         }
//         count++;
//     }
//     count++; // for the final 1
    
//     cout << count << endl;
//     return 0;
// }


int sequence_length(ll n) {
    if (n == 1) {
        return 1;
    }
    if (n % 2 == 1) {
        return 1 + sequence_length(3 * n + 1);
    } else {
        return 1 + sequence_length(n / 2);
    }
}

ll recurse(ll n, ll &count) {
    count++;
    if (n == 1) {
        return count;
    }
    if (n % 2 == 1) {
        return recurse(3 * n + 1, count);
    } else {
        return recurse(n / 2, count);
    }
}

void solve(){
    ll n;
    cin >> n;
    ll count = 0;

    recurse(n, count);
    cout << count << endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
