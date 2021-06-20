// Given an a×b rectangle, your task is to cut it into squares. On each move you can select a rectangle and cut it into two rectangles in such a way that all side lengths remain integers. What is the minimum possible number of moves?

// Input

// The only input line has two integers a and b.

// Output

// Print one integer: the minimum number of moves.

// Constraints
// 1≤a,b≤500
// Example

// Input:
// 3 5

// Output:
// 3

#include<bits/stdc++.h>
using namespace std;

void solve(int n, int m){
    int dp[n+1][m+1];
    
    dp[1][1]=0;
    // for(int i=1;i<n+1;i++){
    //     dp[1][i] = i-1;
    //     dp[i][1] = i-1; 
    // }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(i == j) dp[i][j] = 0;
            else {
                dp[i][j] = 1e9;
                // if(j < i){
                //     dp[i][j] = min(dp[i][j], dp[i-j][j] + 1);
                // } else {
                //     dp[i][j] = min(dp[i][j], dp[i][j-i] + 1);
                // }
                for (int k = 1; k < i; k++) {
                    dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
                }
                for (int k = 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
                }
            }
        }
    }

    // for(int i=1;i<n+1;i++){
    //     for(int j=1;j<m+1;j++){
    //         cout<<dp[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }

    cout<<dp[n][m];
}

int main(){
    int n, m;
    cin>>n>>m;
    solve(n, m);
}