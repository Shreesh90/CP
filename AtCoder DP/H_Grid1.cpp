#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
 
int main() {
    int n,m;
    cin>>n>>m;
    int dp[n][m];
 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c; cin>>c;
            if(c == '.') dp[i][j] = 1;
            else if(c== '#') dp[i][j] = -1;
        }
    }
 
    int flag1 = 0;
    int flag2 = 0;
    for(int i=0;i<n;i++){
        // if(dp[0][i] == -1) flag1=1;
        if(dp[i][0] == -1) flag2=1;
        // if(flag1) dp[0][i] = -1;
        if(flag2) dp[i][0] = -1;
    }
    
    for(int i=0;i<m;i++){
        if(dp[0][i] == -1) flag1=1;
        // if(dp[i][0] == -1) flag2=1;
        if(flag1) dp[0][i] = -1;
        // if(flag2) dp[i][0] = -1;
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(dp[i][j] == -1) continue;
            dp[i][j] = ((dp[i-1][j] == -1?0:dp[i-1][j])%mod + 
                        (dp[i][j-1] == -1?0:dp[i][j-1])%mod)%mod; 
        }
    }
 
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<dp[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }
 
    cout<< (dp[n-1][m-1] == -1 ? 0 : dp[n-1][m-1]%mod ) ;
}