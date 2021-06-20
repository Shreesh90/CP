#include<bits/stdc++.h>
using namespace std;

void edit(string s1, string s2){
    int n = s1.length();
    int m = s2.length();

    int dp[n+1][m+1];

    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i == 0) dp[i][j] = j;
            if(j == 0) dp[i][j] = i;
        }
    }

    dp[0][0] = 0;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){

            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1 + min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
            }
        }
    }

    // for(int i=0;i<n+1;i++){
    //     for(int j=0;j<m+1;j++){

    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<dp[n][m]<<endl;
}

int main(){
    string s1, s2;
    cin>>s1>>s2;
    edit(s1, s2);
}