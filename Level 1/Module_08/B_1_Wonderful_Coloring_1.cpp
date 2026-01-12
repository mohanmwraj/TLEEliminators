//**********************************************************************************
// pbm : https://codeforces.com/contest/1551/problem/B1
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

Paul and Mary have a favorite string 𝑠
 which consists of lowercase letters of the Latin alphabet. They want to paint it using pieces 
 of chalk of two colors: red and green. Let's call a coloring of a string wonderful
  if the following conditions are met:

> each letter of the string is either painted in exactly one color (red or green) or isn't painted;
> each two letters which are painted in the same color are different;
> the number of letters painted in red is equal to the number of letters painted in green;
> the number of painted letters of this coloring is maximum among all colorings of the 
    string which meet the first three conditions.

cont1 -> count of letters with freq 1
cont2 -> count of letters with freq >= 2

*/

void solve(){
    string s; cin >> s;
    int n = s.length();

    vector<int> freq(26, 0);
    for(int i = 0; i < n; i++){
        freq[s[i] - 'a']++;
    }

    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < 26; i++){
        if(freq[i] == 1) cnt1++;
        else if(freq[i] >= 2) cnt2++;   
    }

    int ans = cnt2 + (cnt1 / 2);
    cout << ans << endl;

}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
