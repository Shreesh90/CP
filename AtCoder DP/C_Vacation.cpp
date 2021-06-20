#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int a[n+1] = {0};
    int b[n+1] = {0};
    int c[n+1] = {0};

    for(int i=1;i<n+1;i++){
        cin>>a[i]>>b[i]>>c[i];
    }

    int dp[n+1][3];
    dp[1][0] = a[1];
    dp[1][1] = b[1];
    dp[1][2] = c[1];

    for(int i=2;i<n+1;i++){
        dp[i][0] = a[i] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = b[i] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = c[i] + max(dp[i-1][0], dp[i-1][1]);
    }

    cout<< max(max(dp[n][0], dp[n][1]), dp[n][2]);



}