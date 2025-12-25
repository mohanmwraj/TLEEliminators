//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1762/A
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
    int n; cin >> n;
    int arr[n]; int odd = 0;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        if(arr[i] % 2 != 0) odd++;
    }

    int ans = INT_MAX;
    if(odd % 2 == 0){
        cout << 0 << endl;
        //return;
    } else{
        for(int i = 0; i < n; ++i){
            if(arr[i] % 2 == 0){
                int count = 0;

                while(arr[i]%2 == 0){
                    count++;
                    arr[i] /= 2;
                }

                ans = min(ans, count);
            } else {
                int count = 0;

                while(arr[i] % 2 != 0){
                    count++;
                    arr[i] /= 2;
                }

                ans = min(ans, count);
            }
        }
        cout << ans << endl;
    }

    //cout <<( (ans != INT_MAX )? ans : 0 )<< endl;

}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
