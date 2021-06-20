#include<bits/stdc++.h>
using namespace std;

#define n 8
int x, y;

int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int x, int y, int chess[n+1][n+1]){
    if(x < 1 && x > n && y < 1 && y > n) return false;
    if(chess[x][y] != -1) return false;
    return true; 
}

bool dfs(int x, int y, int mov, int chess[n+1][n+1]){
    if(mov == 65) return true;

    for(int i=0;i<8;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(isValid(nx, ny, chess)){
            chess[nx][ny] = mov;

            if(dfs(nx, ny, mov+1, chess)){
                return true;
            }
            chess[nx][ny] = -1;
        }
    }
    return false;
}

int main()
{   
    int chess[n+1][n+1];
    memset(chess, -1, sizeof(chess));

    cin>>x>>y;
    chess[x][y] = 0;

    if(dfs(x, y, 1, chess)){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<chess[i][j]<<" ";
            }
            cout<<endl;
        }    
    }
    

}   
