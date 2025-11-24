/*
https://www.geeksforgeeks.org/problems/pattern/1

Input: 
n=2
Your Output:
 *
* *
* *
 *

 n=4
 Your Output:
   *
  * *
 * * *
* * * *
* * * *
 * * *
  * *
   *

*/

#include<bits/stdc++.h>

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

class Solution {
  public:
    void printDiamond(int n) {
        // code here
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n - i - 1; ++j){
                cout << " ";
            }
            
            for(int j = 0; j < i + 1; ++j){
                cout << "* ";
            }
            
            cout << endl;
        }
        
        for(int i = n - 1; i >= 0; --i){
            for(int j = 0; j < n - i - 1; ++j){
                cout << " ";
            }
            
            for(int j = 0; j < i + 1; ++j){
                cout << "* ";
            }
            
            cout << endl;
        }
    }
};