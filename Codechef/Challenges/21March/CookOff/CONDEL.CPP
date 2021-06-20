#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t; cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        ll a[n+1], f[n+1]={0};
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            f[i] = f[i-1] + a[i];
        }

        ll mini = f[n];
        for(ll i=k;i<=n;i++){
            mini = min(mini, f[i] - f[i-k]);
        }

        ll ans = ((mini*(mini + 1))/2) + (f[n]-mini);

        cout<<ans<<endl;

    }
}