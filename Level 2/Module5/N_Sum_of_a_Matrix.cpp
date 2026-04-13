//**********************************************************************************
// pbm : https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/N
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
    Given two matrices A and B of size R * C. Print the summation of A and B.

    Note: Solve this problem using recursion.

*/

/*
    By using recursion, iterate with f(i, j) -> f(i, j + 1) if j < m - 1,
    else f(i, j) = f(i + 1, 0)

*/

void solve(){
    int r, c; cin >> r >> c;
    vector<vector<int>> A(r, vector<int>(c));
    vector<vector<int>> B(r, vector<int>(c));
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> A[i][j]; 
        }
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> B[i][j];
        }
    }

    vector<vector<int>> result(r, vector<int>(c));
    function<void(int, int)> add_matrices = [&](int i, int j) {
        if (i == r) return; // Base case: if we've processed all rows
        result[i][j] = A[i][j] + B[i][j]; // Add corresponding elements
        if (j < c - 1) {
            add_matrices(i, j + 1); // Move to the next column
        } else {
            add_matrices(i + 1, 0); // Move to the next row and reset column
        }
    };
    add_matrices(0, 0); // Start from the top-left corner
    // Print the result matrix
    for (const auto& row : result) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }    
    

}

void helper(int row, int col, int maxRow, int maxCol, vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& result) {
    if (row >= maxRow) return; // Base case: if we've processed all rows
    result[row][col] = A[row][col] + B[row][col]; // Add corresponding elements
    if (col < maxCol - 1) {
        helper(row, col + 1, maxRow, maxCol, A, B, result); // Move to the next column
    } else {
        helper(row + 1, 0, maxRow, maxCol, A, B, result); // Move to the next row and reset column
    }
}

int main() {
    int T = 1;
   // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
