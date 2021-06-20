#include<bits/stdc++.h>
using namespace std;
char G[1001][1001];
int visited[1001][1001];
int N, M;

bool isValid(int x, int y){
    if(x<1 || x>N || y<1 || y>M) return false;
    if(visited[x][y] == 1 || G[x][y]=='#') return false;
    return true;

}

void dfs(int x, int y){
    visited[x][y] = 1;

    if(isValid(x-1, y)) dfs(x-1, y);
    if(isValid(x, y+1)) dfs(x, y+1);
    if(isValid(x+1, y)) dfs(x+1, y);
    if(isValid(x, y-1)) dfs(x, y-1);
}

int main()
{
    memset(visited, 0, sizeof(visited));
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>G[i][j];
        }
    }

    int count = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(G[i][j] == '.' && visited[i][j]==0){
                dfs(i, j);
                count++;
            }
        }
    }
    cout<<count;
}