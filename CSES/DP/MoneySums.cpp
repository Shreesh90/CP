#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int main(){

    int n; cin>>n;
    ll MAX_SUM = n*1000;
    long long dp[n+1][MAX_SUM+1];

    vector<int> a(n);
    for(int &v: a) cin>>v;

    for(int i=0;i<n+1;i++){
        for(int j=0;j<MAX_SUM+1;j++){
            if(i==0) dp[i][j] = 0;
            if(j==0) dp[i][j] = 1;
        }
    }
    
    ll count = 0;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<MAX_SUM+1;j++){
            if(a[i-1] <= j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
            if(i==n){
                if(dp[i][j] != 0) count++;
            }
        }
    }
    
    cout<<count<<endl;
    for(int i=1;i<MAX_SUM+1;i++){
        if(dp[n][i] != 0) cout<<i<<" ";
    }
    
}