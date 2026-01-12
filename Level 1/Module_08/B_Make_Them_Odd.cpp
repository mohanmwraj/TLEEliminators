//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1277/B
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
#include <set>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second
/*
There are 𝑛 positive integers 𝑎1,𝑎2,…,𝑎𝑛. For the one move you can choose any even value 𝑐 
and divide by two all elements that equal 𝑐.

For example, if 𝑎=[6,8,12,6,3,12] and you choose 𝑐=6, and 𝑎 is transformed into 𝑎=[3,8,12,3,3,12] 
after the move.

You need to find the minimal number of moves for transforming 𝑎 to an array of only odd integers 
(each element shouldn't be divisible by 2).

Approach:

    Use a set to keep track of the even numbers we have already processed.
    For each number in the array:
        While the number is even and not in the set:
            Add it to the set.
            Divide it by 2.
    The size of the set at the end will be the answer.

    pick the largest even number, divide it by 2 until it becomes odd or we have already seen it.
    keep on doing this for all numbers until all elements are odd.

*/


void solve(){
    int n; cin >> n;

    set<int> st;
    for(int i = 0; i < n; i++){
        int x; cin >> x;

        st.insert(x);
    }

    int ans = 0;
    while(!st.empty()){
        int val = *st.rbegin(); // largest element
        st.erase(val);
        if(val % 2 == 0){
            ans++;
            val = val / 2;
            st.insert(val);
        }
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
