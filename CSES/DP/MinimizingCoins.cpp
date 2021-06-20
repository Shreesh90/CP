// Consider a money system consisting of n coins. 
// Each coin has a positive integer value. 
// Your task is to produce a sum of money x using 
// the available coins in such a way that the number of coins is minimal.

// For example, if the coins are {1,5,7} and the desired sum is 11, 
// an optimal solution is 5+5+1 which requires 3 coins.

// Constraints
// 1 ≤ n ≤ 100
// 1 ≤ x ≤ 10^6
// 1 ≤ ci ≤ 10^6

// RUNTIME ERROR DUE TO LARGE MATRIX SIZE

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
// long long int dp[101][1000003];

int main()
{
    ll n, x;
    cin>>n>>x;
    ll c[n];
    for(ll i=0;i<n;i++){
        cin>>c[i];
    }
    
    ll dp[n+1][x+1];

    for(ll i=0;i<n+1;i++){
        for(ll j=0;j<x+1;j++){
            if(j==0) dp[i][j] = 0;
            if(i==0) dp[i][j] = INT_MAX - 1;
        }
    }

    for(ll i=1;i<n+1;i++){
        for(ll j=1;j<x+1;j++){
            if(c[i-1] <= j){
                dp[i][j] = min( dp[i-1][j], 1 + dp[i][j - c[i-1] ] );
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    if(dp[n][x] == INT_MAX-1) cout<<-1;
    else cout<<dp[n][x];

}

