#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long static dp[101][1000000001];

ll knapsack(ll n, ll W, ll w[], ll v[]){
    if(n==0 || W==0) return 0;

    if(dp[n][W] != -1) return dp[n][W];

    if(w[n] <= W){
        return dp[n][W] = max(v[n] + knapsack(n-1, W-w[n], w, v), knapsack(n-1, W, w, v));
    }
    else {
        return dp[n][W] = knapsack(n-1, W, w, v);
    }
}

int main()
{
    memset(dp, -1, sizeof(dp));
    ll n, W; cin>>n>>W;
    ll w[n+1]={0}, v[n+1]={0};

    for(ll i=1;i<n+1;i++){
        cin>>w[i]>>v[i];
    }

    knapsack(n, W, w, v);
    cout<<dp[n][W];
}