#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, x;
    cin>>n>>x;

    vector<ll> c(n);
    
    for(ll&v : c) cin>>v;

    vector<ll> dp(x+1, 0);
    dp[0] = 1;

    for(ll j=1; j<x+1;j++){
        for(ll i=0;i<n;i++){
            if(c[i] > j) continue;
            dp[j] = (dp[j] + dp[j - c[i]]) % mod;
        }
    }

    cout<<dp[x]%mod<<endl;
} 