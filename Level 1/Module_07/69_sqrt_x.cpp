//**********************************************************************************
// pbm : https://leetcode.com/problems/sqrtx/description/
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
    e^1/2 log x = sqrt(x)
*/

void solve(int x){
    if(x < 2){
        cout << x;
        return;
    } 

    long left = static_cast<long>(exp(0.5 * log(x)));
    long right = left + 1;

    cout << (right * right > x )? right : left;
}

/*

    Binary Search: For x >= 2 the square root is always smaller than x/2 and larger than 0: 0 < a < x/2
    So we can apply binary search in this range to find the largest number whose square is <= x

    s = sqrt(x)
    s*s <= x

    0 1 2 3 4 5 6 ... x/2
    T T T T T T F F F ... F

    > need to find the last T in the array, condition is mid*mid <= x

*/

int sqrtBS(int x){
    if(x < 2){
        return x;
    } 
    ll num;
    int pivot, left = 2, right = x / 2;
    while(left <= right){
        pivot = left + (right - left) / 2;
        num = (ll)pivot * (ll)pivot;
        if(num == x){
            return pivot;
        }
        else if(num < x){
            left = pivot + 1;
        }
        else{
            right = pivot - 1;
        }
    }

    return right;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve(5);
    }
    return 0;
}
