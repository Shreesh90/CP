#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int G[1001][1001];
int visited[1001][1001];
int n,m,sx,sy;

map<pair<int, int>, pair<int, int> > par_mp;
vector<pair<int,int>> moves = {{-1,0}, {1,0}, {0,-1}, {0,1}};
vector<pair<int, int> > monsters;
pair<int, int> s, e;

bool isValid(int x, int y, int timer){
    if(x < 1 || x > n || y<1 || y>m) return false;
    if(G[x][y] <= timer) return false;
    return true;
}

bool isEscape(int x, int y, int timer){
    if(!isValid(x, y ,timer)) return false;
    if(x==1 || y==1 || x==n || y==m) return true;
    return false;
}

bool bfs_escape(){
    queue<pair<pair<int, int>, int > > q;
    q.push({s, 0});
    par_mp[s] = {-1, -1};

    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int timer = q.front().second;
        timer++;
        q.pop();

        for(auto dir: moves){
            int nx = cx + dir.first;
            int ny = cy + dir.second;
            if(isEscape(nx, ny, timer)){
                par_mp[{nx, ny}] = {cx, cy};
                e = {nx, ny};
                return true;   
            }
            if(isValid(nx, ny, timer)){
                par_mp[{nx, ny}] = {cx, cy};
                G[nx][ny] = timer;
                q.push({{nx, ny}, timer});
            }
        }
    }
    return false;
}

void preprocess_lava(){
    queue<pair<pair<int, int>, int > > q;
    for(auto m: monsters){
        q.push({m, 0});
    } 
    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int timer = q.front().second;
        timer++;
        q.pop();

        for(auto dir: moves){
            int nx = cx + dir.first;
            int ny = cy + dir.second;
            if(isValid(nx, ny, timer)){
                G[nx][ny] = timer;
                q.push({{nx, ny}, timer});
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c; cin>>c;
            if(c == '#') G[i][j] = 0;
            else if(c == 'M') {
                G[i][j] = 0;
                monsters.pb({i,j});
            }
            else if(c == 'A'){
                G[i][j] = 0;
                s = {i, j};
            }
            else {
                G[i][j] = INT_MAX;      
            }
        }
    } 

    if(s.first == 0 || s.second == 0 || s.first == n || s.second == m){
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return 0;
    }

    preprocess_lava();

    if(!bfs_escape()){
        cout<<"NO";
        return 0;
    }

    cout<<"YES"<<endl;
    pair<int, int> t = e;
    pair<int, int> t1 = par_mp[e];
    pair<int, int> exit = {-1, -1};
    // vector<char> ans;
    string ans = "";

    while(t1 != exit){
        int yy = t.second - t1.second;
        int xx = t.first - t1.first;

        if(yy==1 && xx==0) ans += "R";
        if(yy==-1 && xx==0) ans += "L";
        if(yy==0 && xx==1) ans += "D";
        if(yy==0 && xx==-1) ans += "U";

        t = par_mp[t];
        t1 = par_mp[t];
    }

    reverse(ans.begin(), ans.end());

    cout<<ans.size()<<endl;
    cout<<ans;

}
