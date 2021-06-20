// Your task is to count the number of ways to construct sum n 
// by throwing a dice one or more times. 
// Each throw produces an outcome between 1 and 6.

// For example, if n=3, there are 4 ways:
// 1+1+1
// 1+2
// 2+1
// 3

// Constraints
// 1 ≤ n ≤ 10^6

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = 1000000007;

int main()
{
    ll n; cin>>n;
    ll dp[n+1] = {0};

    dp[0] = 1;
    dp[1] = 1;

    for(ll i=2;i<n+1;i++){
        for(int j=1;j<=6;j++){
            if(i - j < 0) continue;
            dp[i] = (dp[i]%mod + dp[i-j]%mod)%mod ;
        }
    }
    cout<<dp[n]%mod;

    return 0;
}

