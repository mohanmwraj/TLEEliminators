//MARK:- Test Case ================

int main(){
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "w", stdin);
#endif

    int t; cin >> t;
    while(t--) solve();
    return 0;
}