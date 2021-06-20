#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int n;
vector<int> G[2001];
int vis[2001];
int dist[2001];

int bfs(int x){
    queue<int> q;
    q.push(x);
    vis[x] = 1;
    dist[x] = 0;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int c: G[curr]){
            if(!vis[c]){
                vis[c] = 1;
                q.push(c);
                dist[c] = dist[curr] + 1;
            }
            if(c == x){
                return dist[curr] + 1;
            }
        }
    }
    return -1;
}

int main(){

    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x; cin>>x;
            if(x == 1) G[i].pb(j);
        }
    }

    for(int i=1;i<=n;i++){
        memset(vis, 0, sizeof(vis));
        int ret = bfs(i);
        if(ret != -1) cout<< ret << endl;
        else cout<<"NO WAY"<<endl;
    }
}