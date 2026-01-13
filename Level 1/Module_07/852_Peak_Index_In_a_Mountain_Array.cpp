//**********************************************************************************
// pbm : https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
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
    If the middle element is less than the next element, then the peak lies on the right side of mid.
    Else the peak lies on the left side of mid (including mid).

    0 < 2 > 1 > 0

    2 is peak.

Brute Force: iterate 1 to N - 2

    arr[i] > arr[i - 1] && arr[i] > arr[i + 1] => peak

Time Complexity: O(n)

Binary Search: arr[x-1] < arr[x] > arr[x+1]

    If arr[mid] < arr[mid + 1] => peak on right side
    else peak on left side

    based on this condition, i can make informed decision to move left or right

    while(low < high){
        mid = (low + high) / 2
        if(arr[mid] < arr[mid + 1]){
            low = mid + 1
        }
        else{
            high = mid
        }
    }

    l stores the peak index
    Time Complexity: O(log n)
    Space Complexity: O(1)

*/

void solve(int arr[]){
    int l = 0;
    int r =  sizeof(arr)/sizeof(arr[0]) - 1; // std::size(arr) in C++17
    while(l < r){
        int mid = l + (r - l) / 2;
        if(arr[mid] < arr[mid + 1]){
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        int arr[] = {0,2,1,0};
        solve(arr);
    }
    return 0;
}
