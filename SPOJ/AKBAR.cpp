#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long int
int vis[1000001];
int level[1000001];
int done[1000001];
vector<int> G[1000001];
int flag;

void bfs(int node, int lvl, int lim){
    queue<int> q;
    q.push(node);
    vis[node] = 1;
    level[node] = lvl;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        if(level[curr] > lim) break;
        if(done[curr] == 1){ flag=0; break; }

        for(int c: G[curr]){
            if(!vis[c]){
                vis[c] = 1;
                q.push(c);
                level[c] = level[curr] + 1;
            }
        }
        done[curr] = 1;
    }
    
}

int32_t main()
{
    int t; cin>>t;

    while(t--){
        int n, r, m;
        cin>>n>>r>>m;

        for(int i=0;i<=n;i++){
            G[i].clear();
            vis[i] = 0;
            done[i] = 0;
        }

        for(int i=1;i<=r;i++){
            int x, y; cin>>x>>y;
            G[x].pb(y);
            G[y].pb(x);
        }

        flag=1;
        for(int i=0;i<m;i++){
            int node, s;
            cin>>node>>s;
            bfs(node, 0, s);
            if(flag == 0) break;
        }

        for(int i=1;i<=n;i++){
            if(done[i] == 0) {flag=0; break;}
        }

        if(flag == 0) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;

    }
}

