#include<bits/stdc++.h>
using namespace std;
int g[101][101];
int vis[101][101];
int D[101][101];
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int ret = 0;

bool isValid(int x, int y){
    if(x<1 || x>n || y < 1 || y>m) return false;
    if(vis[x][y]) return false;
    return true;
}

void bfs(){
    queue<pair<int, int> > q;
    q.push({1,1});
    D[1][1] = g[1][1];
    vis[1][1] = 1;

    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int newx = curx + dx[i];
            int newy = cury + dy[i];
            if(isValid(newx, newy)){
                int d = max(D[curx][cury], g[newx][newy]);
                if(D[newx][newy] > d){
                    q.push({newx, newy});
                    D[newx][newy] = max(D[curx][cury], g[newx][newy]);
                    vis[newx][newy] =1;
                }
            }
        }
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        ret=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>g[i][j];
            }
        }  

        bfs();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<D[i][j]<<" ";
                if(i == 1 || i == n || j == 1 || j == m) continue;
                ret += D[i][j] - g[i][j];
            }
            cout<<endl;
        }

        cout<<ret<<endl;
    }
}