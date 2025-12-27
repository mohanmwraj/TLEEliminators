//**********************************************************************************
// pbm : https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/B
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

int binarySearch(int n, vector<int> &arr, int x){
    int left = 0;
    int right = n - 1;
    int ans = -1;

    while(left <= right){
        int mid = left + (right - left) / 2;

        if(arr[mid] <= x){
            ans = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    return ans + 1;
}

void solve(){
    int n, queries;
    cin >> n >> queries;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    for(int i = 0; i < queries; ++i){
        int x; cin >> x;

        cout << binarySearch(n, arr, x) << endl;
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
