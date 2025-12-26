//**********************************************************************************
// pbm : https://atcoder.jp/contests/caddi2018b/tasks/caddi2018_a
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
#include<numeric>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

/*
    Given two integers N and P, are not less than 1.
    The values of a1, a2, ..., aN are not known, but it is known that the product of these N integers is P.
    Find the maximum possible value of gcd(a1, a2, ..., aN).

    a1, a2, ..., aN
    g = greatest common divisor of a1, a2, ..., aN all integers.
    p = product of a1, a2, ..., aN
    then g^n divides p.

    then a1, a2, ..., aN can be expressed as:
    a1 = g * b1
    a2 = g * b2
    .
    aN = g * bN

    ai = ci * g for i = 1 to N

    then product of a1, a2, ..., aN
    p = a1 * a2 * ... * aN
      = (c1 * g) * (c2 * g) * ... * (cN * g)
      = (c1 * c2 * ... * cN) * g^N

    2 4 10 6 18
    g = 2

    1(2) 2(2) 5(2) 3(2) 9(2)

    c1 = 1
    c2 = 2
    c3 = 5          
    c4 = 3
    c5 = 9
    c1 * c2 * ... * cN = 1 * 2 * 5 * 3 * 9 = 270

*/
int gcd_int(int a,int b){
  if(a<0) a=-a; if(b<0) b=-b;
  while(b){ int t=a%b; a=b; b=t; }
  return a;
}
void solve(){
    ll x, y;
    cin >> x >> y;
    ll product = x * y;
    ll gcd = gcd_int(x, y);
    cout << product << " " << gcd << endl;
}


int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
