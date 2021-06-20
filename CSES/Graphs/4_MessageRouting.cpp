#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> G[100001];
int visited[100001];
int par[100001];
int dist[100001];

void bfs(int x, int p=-1, int lvl=0){
    queue<int> q;
    q.push(x);
    visited[x]=1;
    par[x]=p;
    dist[x]=lvl;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int c: G[curr]){
            if(!visited[c]){
                q.push(c);
                visited[c]=1;
                par[c] = curr;
                dist[c] = dist[curr]+1;
            }
        }

    }
}

int main()
{
    int n, m;
    cin>>n>>m;
    memset(par, -1, sizeof(par));
    memset(dist, -1, sizeof(dist));
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    bfs(1);

    if(dist[n] == -1) cout<<"IMPOSSIBLE"<<endl;
    else {
        cout<<dist[n]+1<<endl;
        vector<int> p;
        while(n != -1){
            p.pb(n);
            n = par[n];
        }
        reverse(p.begin(), p.end());
        for(int x: p) cout<<x<<" ";
        cout<<endl;

    }
}
