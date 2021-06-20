#include<bits/stdc++.h>
using namespace std;

int n, m, j;
int sx,sy,ex,ey;
int cnt=0;
int g[41][41];
int vis[41][41];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool isValid(int x, int y){
    if(x < 1 || x > n || y < 1 || y > m) return false;
    if(vis[x][y] || g[x][y] == 0) return false;
    return true;
}

void bfs(){
    queue<pair<int,int> > q;
    q.push({sx,sy});    
    vis[sx][sy] = 1;

    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        if(g[curx][cury] == 2) cnt++;
        if(curx == ex and cury == ey) return;

        for(int i=0;i<4;i++){
            int newx = curx + dx[i];
            int newy = cury + dy[i];
            if(isValid(newx, newy)){
                vis[newx][newy] = 1;
                q.push({newx, newy});
            }
        }
    }
}

int main() {
    cin>>n>>m>>j;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c; cin>>c;
            if(c == '#') g[i][j] = 0;
            if(c == 's') g[i][j] = 2;
            else g[i][j] = 1;
            
            if(c == '@'){sx = i, sy = j;}
            if(c == 'x') {ex = i, ey = j;}
        }
    }

    bfs();
    if(2*cnt <= j) cout<<"SUCCESS";
    else cout<<"IMPOSSIBLE";
}