#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k; cin>>n>>k;
    vector<int> h(n+1, 0), dp(n+1, INT_MAX);

    for(int i=1;i<n+1;i++){
        int x; cin>>x;
        h[i] = x;
    }
    dp[0] = dp[1] = 0;
    dp[2] = abs(h[2] - h[1]);

    for(int i=3;i<n+1;i++){
        for(int j=1;j<=k;j++){
            if(i-j >= 1){
                dp[i] = min(abs(h[i]-h[i-j]) + dp[i-j], dp[i]);
            }
        }
        
    }

    cout<<dp[n];


}