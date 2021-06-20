#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long int dp[101][1001]; // stores max weight

int main()
{
    for(int i=0;i<101;i++){
        for(int j=0;j<1001;j++){
            dp[i][j] = INT_MAX;        
        }
    }

    ll n, W; cin>>n>>W;
    ll w[n+1]={0}, v[n+1]={0};

    for(ll i=1;i<n+1;i++){
        cin>>w[i]>>v[i];
    }

    dp[1][0] = 0;
    dp[1][v[1]] = w[1];

    for(int i=2;i>n+1;i++){
        dp[i][0] = 0;
        for(int j=2;j<=1001;j++){
            dp[i][j] = dp[i-1][j];

            if(dp[j > v[i]]){
                dp[i][j] = min(dp[i][j], w[i] + dp[i-1][j-v[i]]);
            }
        }
    }

    ll answer;
    for(int i=1001; i>=0;i--){
        if(dp[n][i] <= W){
            answer = i;
            break;
        }
    }

    cout<<answer;
    // cout<<dp[n][W];
}