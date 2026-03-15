//**********************************************************************************
// pbm : 
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

    prefix sum P[i][j] = sum of all elements of the from grid[x][y] such that x <= i and y <= j.

    To find prefix sum of a submatrix from (l1, r1) to (l2, r2), we can use the formula:

    sum = P[l2][r2] - P[l1 - 1][r2] - P[l2][r1 - 1] + P[l1 - 1][r1 - 1]

    Explanation of the formula:

    P[L1-1][R2] = sum of elements from (0, 0) to (L1-1, R2) which is the top region that we need to subtract.
    P[L2][R1-1] = sum of elements from (0, 0) to (L2, R1-1) which is the left region that we need to subtract.
    P[L1-1][R1-1] = we subtract twice when we subtract left and top regions, so we need to add once.

    To calculate prefix sum, we can use the following formula:

    P[i][j] = grid[i][j] + P[i-1][j] + P[i][j-1] - P[i-1][j-1]
*/

/*
    Time Complexity : O(n*m) for preprocessing, O(1) for each query, O(n*m + q) for q queries.
    Space Complexity : O(n*m) for prefix sum array.

*/

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> prefix(n, vector<int>(m));
    prefix[0][0] = grid[0][0];

    // // First column
    // for(int i = 1; i < n; i++){
    //     prefix[i][0] = prefix[i-1][0] + grid[i][0];
    // }

    // // First row
    // for(int j = 1; j < m; j++){
    //     prefix[0][j] = prefix[0][j-1] + grid[0][j];
    // }

    // for(int i = 1; i < n; i++){
    //     for(int j = 1; j < m; j++){
    //         prefix[i][j] = grid[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
    //     }
    // }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            // prefix[i][j] = grid[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];

            prefix[i][j] = grid[i][j] + 
                                (i > 0 ? prefix[i-1][j] : 0) + 
                                (j > 0 ? prefix[i][j-1] : 0) - 
                                (i > 0 && j > 0 ? prefix[i-1][j-1] : 0);
        }
    }

    int q; cin >> q;
    while(q--){
        int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
        l1--; r1--; l2--; r2--;
        int sum = prefix[l2][r2] - 
                        (l1 > 0 ? prefix[l1-1][r2] : 0) - 
                        (r1 > 0 ? prefix[l2][r1-1] : 0) + 
                        (l1 > 0 && r1 > 0 ? prefix[l1-1][r1-1] : 0);

        cout << sum << endl;    
    }

}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
