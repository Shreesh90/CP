#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int W = 8001;
const int n = 4001;
int dp[n][W];

int main()
{

    for(int i=0;i<n;i++){
        for(int j=0;j<W;j++){
            if(j==0) dp[i][j] = 2;
            if(i==0) dp[i][j] = 0;
        }
    }

    dp[1][0] = -1;

    int t; cin>>t;
    while(t--){
        int s,k;
        cin>>s>>k;
        int arr[s];
        for(int i=0;i<s;i++) cin>>arr[i];

        for(int i=1;i<s+1;i++){
            for(int j=1;j<2*k + 1; j++){
                
                if(arr[i-1] < j){
                    dp[i][j] = max(1 + dp[i-1][j-arr[i-1]],  dp[i-1][j]);
                } else{ 
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        cout<<dp[s][2*k]<<endl;
    }
}
