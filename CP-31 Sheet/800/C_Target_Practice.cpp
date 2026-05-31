//**********************************************************************************
// pbm : https://codeforces.com/problemset/problem/1873/C
//**********************************************************************************
#include<bits/stdc++.h>

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

const int score[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
    {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
    {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
    {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
    {1, 2, 3, 4, 5, 5, 4, 3, 2 ,1},
    {1 ,2 ,3 ,4 ,4 ,4 ,4 ,3 ,2 ,1},
    {1 ,2 ,3 ,3 ,3 ,3 ,3 ,3 ,2 ,1},
    {1 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,1},
    {1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1}
};

// Solution from TLE Eliminator.
void solve1(){
    char a[10][10];
    for(int i = 0; i < 10; ++i){
        string s; cin >> s;
        for(int j = 0; j < 10; ++j){
            a[i][j] = s[j];
        }
    }

    int total_score = 0;
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            if(a[i][j] == 'X'){
                total_score += score[i][j];
            }
        }
    }

    cout << total_score << endl;
}

//My solution.
void solve(){
    int sum = 0;
    for(int i = 0; i < 10; ++i){
        string s; cin >> s;

        for(int j = 0; j < 10; ++j){
            if(s[j] == 'X'){
                if((i == 0 || j == 0) || (i == 9 || j == 9)){
                    sum += 1;
                } else if((i == 1 || j == 1) || (i == 8 || j == 8)){
                    sum += 2;
                } else if((i == 2 || j == 2) || (i == 7 || j == 7)){
                    sum += 3;
                } else if((i == 3 || j == 3) || (i == 6 || j == 6)){
                    sum += 4;
                } else if((i == 4 || j == 4) || (i == 5 || j == 5)){
                    sum += 5;
                }
            }
        }
    }

    cout << sum << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
