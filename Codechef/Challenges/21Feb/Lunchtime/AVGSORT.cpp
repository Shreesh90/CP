#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        ll a[n];
        int flag=0;
        for(ll i=0;i<n;i++) cin>>a[i];

        for(ll i=1;i<n;i++){
            if(a[i] > a[i-1]) flag=1;    
        }

        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
}