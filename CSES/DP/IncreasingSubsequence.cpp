#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
    ll n; cin>>n;

    vector<ll> a(n), dp(n, 1);
    for(ll &v: a) cin>>v;
    dp[0] = 1;
    
    ll ret = INT_MIN;

    for(ll i=1;i<n;i++){
        // ll flag=0;
        // ll maxi = INT_MIN;
        for(ll j=0;j<i;j++){
            if(a[j] < a[i] && dp[i] < dp[j]+1){
                // maxi = max(maxi, dp[j]);
                // flag=1;
                dp[i] = dp[j]+1;
            }
        }
        // if(flag) dp[i] = 1+maxi;
        // else dp[i] = 1;
        ret = max(dp[i], ret);
    }
    cout<<ret;
}