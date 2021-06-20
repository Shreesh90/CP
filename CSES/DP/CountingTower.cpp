#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define endl "\n"

int main()
{
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        int dp[n+2][2];
        dp[n+1][0] = dp[n+1][1] = 1;

        for(int i=n;i>=2;i--){
            ll a = (dp[i+1][0] + dp[i+1][1])%mod;
            ll b = (dp[i+1][0]);
            ll c = (2 * dp[i+1][0])%mod;
            ll d = dp[i+1][1];

            dp[i][0] = (a+b+c)%mod;
            dp[i][1] = (a+d)%mod;
        }

        cout<< (dp[2][1] + dp[2][0])%mod<<endl;
    }
}
