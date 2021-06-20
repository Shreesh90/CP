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

    int n, x;
    cin>>n>>x;

    vector<int> c(n);
    for(int&v : c) cin>>v;

    int dp[n+1][x+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<x+1;j++){
            if(i==0) dp[i][j] = 0;
            if(j==0) dp[i][j] = 1;
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<x+1;j++){
            if(c[i-1] <= j){
                dp[i][j] = (dp[i-1][j]%mod + dp[i][j-c[i-1]]%mod)%mod;
            } else {
                dp[i][j] = dp[i-1][j] % mod;
            }
        }
    }

    cout<<dp[n][x]%mod;

} 