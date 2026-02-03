//**********************************************************************************
// pbm : https://www.codechef.com/problems/MAXAND18
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

Choose a positive integer X that has exactly K bits set to 1 in binary representation 
(i.e., the binary representation of X contains exactly K ones).

sum s = summation of i = 1 to N of (X ^ Ai)

// Mathematically: S = Σ(X ⊕ Aᵢ) for i = 1 to N
// We need to maximize S by choosing X with exactly K set bits

For X = 3 (011):
A[1] = 3 = 011,  X ^ A[1] = 011 ^ 011 = 000 = 0
A[2] = 5 = 101,  X ^ A[2] = 011 ^ 101 = 110 = 6
A[3] = 6 = 110,  X ^ A[3] = 011 ^ 110 = 101 = 5
                 ─────────────────────────────
                 s = 0 + 6 + 5 = 11

For X = 5 (101):
A[1] = 3 = 011,  X ^ A[1] = 101 ^ 011 = 110 = 6
A[2] = 5 = 101,  X ^ A[2] = 101 ^ 101 = 000 = 0
A[3] = 6 = 110,  X ^ A[3] = 101 ^ 110 = 011 = 3
                 ─────────────────────────────
                 s = 6 + 0 + 3 = 9
So to minimize the sum, you want X to have 1s in bit positions 
where most array elements also have 1s (more matches → more zeros → smaller XOR values).

Maximize S minimize X.

Ai <= 10^9 == 31 bits

consider 5 numbers that bit 0 is set bit -> 2^0 * 5

we can rewrite the summation as:
S = Σ(Σ(2^j) for each bit j where X has a 1) for i = 1 to N

Σ jth bit in x for each j = 0 to 30 * Σ jth bit in Ai for each i = 1 to N
Mathematical Representation:

S = Σ(X ⊕ Aᵢ) for i = 1 to N

Breaking down by bit positions:
S = Σ(i=1 to N) Σ(j=0 to 30) [2^j × (X[j] ⊕ Aᵢ[j])]

Rearranging (sum over bits first, then elements):
S = Σ(j=0 to 30) [2^j × Σ(i=1 to N) (X[j] ⊕ Aᵢ[j])]

Let count[j] = number of elements where bit j is set in Aᵢ

For bit position j:
- If X[j] = 1: contributes to XOR when Aᵢ[j] = 0 → (N - count[j]) contributions
- If X[j] = 0: contributes to XOR when Aᵢ[j] = 1 → count[j] contributions

Therefore:
S = Σ(j=0 to 30) [2^j × (X[j] × (N - count[j]) + (1 - X[j]) × count[j])]

Simplifying:
S = Σ(j=0 to 30) [2^j × (count[j] + X[j] × (N - 2×count[j]))]

To maximize S with exactly K set bits:
contribution[j] = 2^j × |N - 2×count[j]|
Select K bits with maximum contribution where X[j] = 1 if (N - count[j]) > count[j]


5 numbers that have bit 0 as set bit

- contribution from bit 0 if X has a set bit = 2^0 * 5
- contribution from bit 0 if X does not have a set bit at position 0 = 0


*/

/*
Goal: Maximize S = Σ(X ⊕ Aᵢ) for i = 1 to N

Key Insight:
For each bit position j (0 to 30):
- Let count[j] = number of elements in A where bit j is set
- If X has bit j set (X[j] = 1):
    * Contributes 2^j × (N - count[j]) to sum S
- If X has bit j unset (X[j] = 0):
    * Contributes 2^j × count[j] to sum S

Formula:
S = Σ(j=0 to 30) [2^j × (X[j] × (N - count[j]) + (1 - X[j]) × count[j])]

Simplification:
S = Σ(j=0 to 30) [2^j × (N - 2×count[j]×X[j] + count[j]×X[j])]
S = Σ(j=0 to 30) [2^j × (count[j] + X[j]×(N - 2×count[j]))]

Strategy to maximize S:
- For each bit j, contribution when X[j]=1 is: 2^j × (N - count[j])
- For each bit j, contribution when X[j]=0 is: 2^j × count[j]
- Set X[j]=1 if (N - count[j]) > count[j], i.e., count[j] < N/2
- Pick K bits with largest positive contribution: 2^j × |N - 2×count[j]|

Constraints: Aᵢ ≤ 10^9 → 31 bits needed

*/

void solve(){
    ll n, k; 
    cin >> n >> k;

    vector<ll> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    } 

    vector<pair<ll, ll>> contributions(31); // pair of (contribution, bit position)
    for(int bit = 0; bit < 31; ++bit){
        ll countSetBits = 0;
        for(int i = 0; i < n; ++i){
            if(v[i] & (1 << bit)) countSetBits++;
        }
        // ll contributionIfSet = (n - countSetBits) * (1LL << bit);
        // ll contributionIfUnset = countSetBits * (1LL << bit);
        // ll netContribution = contributionIfSet - contributionIfUnset;
        contributions[bit] = {(countSetBits*(1 << bit)), bit*-1};//{netContribution, bit};

        // bit * -1 to sort in descending order based on contribution when we do ascending sort
        // We want to maximize the contribution, so we take the absolute value
    }

    sort(contributions.rbegin(), contributions.rend()); // To take top k contributions, so sort in descending order
    ll ans = 0;
    for(int i = 0; i < k; ++i){
        int bitToSet = abs(contributions[i].second);
        ans = (ans | (1LL << bitToSet));
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

