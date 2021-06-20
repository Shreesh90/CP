#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    vector<int> h(n+1, 0), dp(n+1, 0);

    for(int i=1;i<n+1;i++){
        int x; cin>>x;
        h[i] = x;
    }
    dp[2] = abs(h[2] - h[1]);

    for(int i=3;i<n+1;i++){
        dp[i] = min(abs(h[i]-h[i-1]) + dp[i-1], abs(h[i]-h[i-2]) + dp[i-2]);
    }

    cout<<dp[n];


}