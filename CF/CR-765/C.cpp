#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){

    ll n,l,k; 
    cin>>n>>l>>k;

    vector<ll> dist(n+2, 0), speed(n+2, 0);

    for(ll i=1;i<=n;i++){
        cin>>dist[i];
    }
    for(ll i=1;i<=n;i++){
        cin>>speed[i];
    }
    
    dist[n+1] = l;
    vector<vector<ll>> dp(n+3, vector<ll>(n+3, INT_MAX));
    
    dp[1][0] = 0;
    for(ll i=2;i<=n+1;i++){
        for(ll j=0;j<=k;j++){
            if(k==0){
                dp[i][j] = dp[i-1][j] + (dist[i] - dist[i-1])*speed[i-1];
            }
            else {
                for(ll prev=i-1;prev>0;prev--){
                    ll toremove = i - prev - 1;
                    if(toremove <= j){
                        dp[i][j] = min(dp[i][j], dp[prev][j-toremove]+(dist[i] - dist[prev])*speed[prev]);
                    }
                }
            }
        }
    }
    ll ret = INT_MAX;
    for(ll i=0;i<=k;i++){
        ret = min(ret, dp[n+1][i]);
    }
    cout<<ret<<"\n";
}
