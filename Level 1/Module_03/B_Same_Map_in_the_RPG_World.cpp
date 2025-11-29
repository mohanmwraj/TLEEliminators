//**********************************************************************************
// pbm : https://atcoder.jp/contests/abc300/tasks/abc300_b
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
   - need to make A(i, j) == B(i, j) for all integer pairs (i, j)
   - Allowed operation are vertical and horizontal shift on single element
   - (i, j) = [(i + s) % h][(j + t) % w], s = vertical shifts, t = horizontal shifts.
   - After (s, t) = (1, 1), index present at (2, 2) will comes to (1, 1).
   - s = 0 -> h - 1, possible combinations after that same pattern will repeat
   - t = 0 -> w - 1.

*/

void solve(){
    int h, w; cin >> h >> w;
    int a[h][w], b[h][w];

    for(int i = 0; i < h; ++i){
        string s; cin >> s;
        for(int j = 0; j < w; ++j){
            if(s[j] == '.') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }

    for(int i = 0; i < h; ++i){
        string s; cin >> s;
        for(int j = 0; j < w; ++j){
            if(s[j] == '.') b[i][j] = 0;
            else b[i][j] = 1;
        }
    }

    for(int s = 0; s < h; ++s){
        for(int t = 0; t < w; ++t){

            bool done = true;

            for(int i = 0; i < h; ++i){
                for(int j = 0; j < w; ++j){
                    if(a[i][j] != b[(i + s) % h][(j + t) % w]){
                        done = false;
                        break;
                    }
                }
                if(!done) break;
            }
            if(done){
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
