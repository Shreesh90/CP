#include<bits/stdc++.h>
using namespace std;

int is_prime(int ans){
    for(int i=2;i*i<=ans;i++){
        if(ans%i == 0) return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 1000000;
    while(1){
        if(is_prime(ans)) break;
        ans++;
    }

    int t; cin>>t;
    while(t--){
        int l, r;
        cin>>l>>r;
        cout<<ans<<"\n";
    }
}