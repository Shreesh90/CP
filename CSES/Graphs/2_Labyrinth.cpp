#include<bits/stdc++.h>
using namespace std;
#define pb push_back
char G[1001][1001];
int n,m,sx,sy,ex,ey;
int visited[1001][1001];

vector<vector<pair<int, int> > > path(1001, vector<pair<int, int> > (1001));
vector<pair<int,int>> moves = {{-1,0}, {1,0}, {0,-1}, {0,1}};

bool IsValid(int x, int y){
    if(x<1 || x>n || y<1 || y>m) return false;
    if(visited[x][y] == 1 || G[x][y] == '#') return false;
    return true;
}

void bfs(int x, int y){
    queue<pair<int, int> > q;
    q.push({x,y});
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(auto dir: moves){
            int dx = dir.first;
            int dy = dir.second;
            if(IsValid(cx+dx, cy+dy)){
                q.push({cx+dx, cy+dy});
                visited[cx+dx][cy+dy]=1;
                path[cx+dx][cy+dy] = {cx,cy};
            }
        }

    }
}

int main(){

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            path[i][j] = {-1,-1};
            cin>>G[i][j];
            if(G[i][j] == 'A') {sx=i;sy=j;}
            if(G[i][j] == 'B') {ex=i;ey=j;}
        }
    } 

    bfs(sx,sy);

    if(visited[ex][ey]) cout<<"YES"<<endl;
    else {cout<<"NO"<<endl; return 0;}

    vector<pair<int, int> > ans;
    while(ex != sx || ey != sy){
        pair<int, int> par = path[ex][ey];
        ans.pb({ex - par.first, ey - par.second});
        ex = par.first; ey = par.second; 
    } 
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    string ret = "";
    for(auto it: ans){
        int xx = it.first;
        int yy = it.second;
        if(xx == 0 && yy == -1) ret += "L";
        if(xx == 0 && yy == 1) ret += "R";
        if(xx == -1 && yy == 0) ret += "U";
        if(xx == 1 && yy == 0) ret += "D";
    }
    cout<<ret;
}