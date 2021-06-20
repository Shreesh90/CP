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

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n, x;
    cin>>n>>x;
    ll c[n];
    for(ll i=0;i<n;i++){
        cin>>c[i];
    }

    vector<ll> dp(1e6+1, 1e9);

    dp[0] = 0;
    for(int i=0;i<x+1;i++){
        for(int j=0;j<n;j++){
            if(c[j] <= i){
                dp[i] = min(dp[i], 1 + dp[i - c[j]]);
            }
        }
    }

    cout<< (dp[x] == 1e9 ? -1 : dp[x]);

}

