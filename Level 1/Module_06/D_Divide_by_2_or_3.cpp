//**********************************************************************************
// pbm : https://atcoder.jp/contests/abc276/tasks/abc276_d
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

int gcd_int(int a, int b){
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while(b){
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

/*
    You are given an array of n integers. You can perform the following operation any number of times (including zero):

    - Choose an index i (1 ≤ i ≤ n) such that ai is even, and replace ai with ai / 2.
    - Choose an index i (1 ≤ i ≤ n) such that ai is divisible by 3, and replace ai with (2 * ai) / 3.

    Your task is to determine the minimum number of operations required to make all elements of the array equal.

    Any numbers will be a factor of 2 and 3 and k.
    a1 = 2^x1 * 3^y1 * k1
    a2 = 2^x2 * 3^y2 * k2
    .
    an = 2^xn * 3^yn * kn
    To make all elements equal, all k1, k2, ..., kn must be equal.
    If they are not equal, it is impossible to make all elements equal.

    Let min_x = min(x1, x2, ..., xn)
    Let min_y = min(y1, y2, ..., yn)    
    minimum operations required to make all elements equal is:
    (|x1 - min_x| + |y1 - min_y|) + (|x2 - min_x| + |y2 - min_y|) + ... + (|xn - min_x| + |yn - min_y|)
    
    consider two numbers 
    2^2 * 3^1 * k    2^3 * 3^0 * k

    gcd will be 2^2 * 3^0 * k

    if you divide first number with gcd, you will get 3^1 => 1 operation
    if you divide second number with gcd, you will get 2^1  => 1 operation
    total operations = 2

*/
int __gcd_int(int a,int b){
  if(a<0) a=-a; if(b<0) b=-b;
  while(b){ int t=a%b; a=b; b=t; }
  return a;
}

void solve(){
    int n; cin >> n;
    //vector<int> a(n);
    int a[n];

    int g = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        g = __gcd_int(g, a[i]);
    } 

    int ans = 0;
    for (int  i = 0; i < n; i++)
    {
        int temp = a[i] / g;
        while (temp % 2 == 0){
            temp /= 2;
            ans++;
        }
        while (temp % 3 == 0){
            temp /= 3;
            ans++;  
        }
        if (temp != 1){
            cout << -1 << endl;
            return;
        }
    }
    cout << ans << endl;
    
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
