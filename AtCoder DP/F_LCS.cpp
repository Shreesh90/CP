#include<bits/stdc++.h>
using namespace std;
int dp[3001][3001];

int main()
{
    string a,b;
    cin>>a>>b;

    for(int i=0;i<3001;i++){
        for(int j=0;j<3001;j++){
            if(i==0 || j==0) dp[i][j]=0;
        }
    }

    for(int i=1;i<a.length()+1;i++){
        for(int j=1;j<b.length()+1;j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string ret = "";

    int i = a.length(), j=b.length();
    while(i>0 && j>0){
        if(a[i-1] == b[j-1]){
            ret.push_back(a[i-1]);
            i--;j--;
        }
        else {
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }

    reverse(ret.begin(), ret.end());
    cout<<ret;

}