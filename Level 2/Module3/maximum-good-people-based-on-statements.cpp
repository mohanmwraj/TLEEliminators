//********************************************************************************************
// pbm : https://leetcode.com/problems/maximum-good-people-based-on-statements/description/
//********************************************************************************************
#include<bits/stdc++.h>

#include<iostream>
using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

/*
    Good Person: The person who always tells the truth.
    Bad Person: The person who may tell the truth or may lie.

    you are given a 0-indexed 2D integer array statements of size n x n that represents the statements made
    by n people about each other. statements[i][j] can be one of the three values:
    0: Person i states that person j is a bad person.
    1: Person i states that person j is a good person.
    2: Person i makes no statement about person j.
    Note that statements[i][i] = 2 for all 0 <= i < n.

    Return the maximum number of people who can be good based on the statements made by the n people.

*/

/*

    Set bit will tell me that the person is good, unset bit will tell me that the person is bad.
    For every combination of good and bad people, we will check if the statements made by the good people
    are consistent with the assumed good/bad status of all people.
    If they are consistent, we will count the number of good people in that combination and update the maximum count if needed.
    Finally, we will return the maximum count of good people found across all combinations. 

*/

void solve(vector<vector<int>>& statements){
    int n = statements.size();
    int maxGoodPeople = 0;

    for(int mask = 0; mask < (1 << n); mask++){
        bool isValid = true;
        for(int i = 0; i < n; i++){
            if((mask & (1 << i)) == 0) continue; // person i is bad, skip their statements

            for(int j = 0; j < n; j++){
                if(statements[i][j] == 2) continue; // no statement about person j

                if(statements[i][j] == 1 && (mask & (1 << j)) == 0){
                    isValid = false; // person i says j is good, but j is bad in this combination
                    break;
                }
                
                if(statements[i][j] == 0 && (mask & (1 << j)) != 0){
                    isValid = false; // person i says j is bad, but j is good in this combination
                    break;
                }
            }

            if(!isValid) break;
        }
        if(isValid){
            int goodCount = __builtin_popcount(mask);
            maxGoodPeople = max(maxGoodPeople, goodCount);
        }
    }
}

int main() {
    int T = 1;
    cin >> T;
    vector<vector<int>> statements;
    while(T--){
        solve(statements);
    }
    return 0;
}
