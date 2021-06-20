#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, W;
    cin>>n>>W;

    int dp[n+1][W+1];
    
    int w[n], v[n];
    for(int i=0;i<n;i++) cin>>w[i];
    for(int i=0;i<n;i++) cin>>v[i];

    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i==0 || j==0) dp[i][j] = 0;
        }
    }

    for (int i=1; i<n+1; i++){
        for(int j=1; j<W+1;j++){
            if(w[i-1] <= j){
                dp[i][j] = max(v[i-1] + dp[i-1][j - w[i-1]],
                                dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    cout<<dp[n][W];
    

}