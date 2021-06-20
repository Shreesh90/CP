#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int m,n;
int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,-1,1,1,-1};
char G[55][55];
int dp[55][55];
int ret = -1;

bool isValid(int x, int y, int q, int w){
    if(x < 1 or x > m or y < 1 or y > n) return false;
    if(G[x][y] - G[q][w] != 1) return false; 
    return true;
}

int dfs(int x, int y){
    if(dp[x][y] != -1) return dp[x][y];

    int ans = 0;
    for(int i=0;i<8;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(isValid(nx, ny, x, y)){
            ans = max(ans, dfs(nx, ny));
        }
    }

    ans += 1;
    return dp[x][y] = ans;
}

int main(){
    int t=0;

    while(1){        
        cin>>m>>n;
        if(n==0 and m==0) break;
        t++;
        memset(dp, -1, sizeof(dp));

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                char c; cin>>c;
                G[i][j] = c;
            }
        }

        ret = 0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(G[i][j] == 'A' ){
                    ret = max(ret, dfs(i, j));
                }
            }
        }
        
        printf("Case %d: %d\n", t, ret);

    }
}