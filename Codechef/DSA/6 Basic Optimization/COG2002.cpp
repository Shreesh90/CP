#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t; cin>>t;
    
    while(t--){
        ll n; cin>>n;

        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];

        ll init = a[0] + a[1] + a[2];
        ll ans = init;

        for(ll i=3; i<n; i++){
            ll cur = init - a[i-3] + a[i];
            ans = max(ans, cur);
            init = cur;
        }

        ans = max(ans, a[n-2] + a[n-1] + a[0]);
        ans = max(ans, a[n-1] + a[0] + a[1]);

        cout<<ans<<"\n";
    }
}