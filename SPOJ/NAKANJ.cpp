#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n";
int sx,sy,ex,ey;
map<char, int> ind;
int dx[] = {2, 1, 2, 1, -2, -2, -1, -1};
int dy[] = {1, 2, -1, -2, 1, -1, 2, -2};
int N = 8;
int dist[9][9];
int vis[9][9];

bool isValid(int x, int y){
    if(x < 1 || x > N || y < 1 || y > N) return false;
    if(vis[x][y]) return false;
    return true;
}

int bfs(){
    queue<pair<int, int> > q;
    q.push({sx, sy});
    dist[sx][sy] = 0;
    vis[sx][sy] = 1;

    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        if(curx == ex and cury == ey) return dist[curx][cury];

        for(int i=0;i<8;i++){
            int newx = curx + dx[i];
            int newy = cury + dy[i];

            if(isValid(newx, newy)){
                dist[newx][newy] = dist[curx][cury] + 1;
                vis[newx][newy] = 1;
                q.push({newx, newy});
            }
        }
    }
}

int32_t main()
{
    ind['a'] = 1;
    ind['b'] = 2;
    ind['c'] = 3;
    ind['d'] = 4;
    ind['e'] = 5;
    ind['f'] = 6;
    ind['g'] = 7;
    ind['h'] = 8;

    int t; cin>>t;
    while(t--){
        memset(vis, 0, sizeof(vis));
        string s, e;
        cin>>s>>e;
        sx = ind[s[0]];
        sy = s[1] - '0';
        ex = ind[e[0]];
        ey = e[1] - '0';
        cout<<bfs()<<endl;
    }

}