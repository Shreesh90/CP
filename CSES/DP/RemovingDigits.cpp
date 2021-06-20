#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
 
int main()
{
    int n;
    cin>>n;

    int dp[n+1];
    for(int i=0;i<n+1;i++) dp[i] = INT_MAX-1;
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2;i<n+1;i++){
        int x = i;
        while(x != 0){
            int t = x%10;
            dp[i] = min(dp[i], 1+dp[i-t]);
            x /= 10;
        }
    }

    cout<<dp[n];

}