#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> G[10001];
int visited[10001], in[10001],low[10001];
int timer=1;
set<int> ap;

void dfs(int node, int p){
    visited[node]=1;
    in[node] = low[node] = timer;
    timer++;
    int children=0;

    for(int child: G[node]){
        if(child == p) continue;
        if(visited[child]){
            low[node] = min(low[node], in[child]);
        }
        else {
            dfs(child, node);
            if(low[child] >= in[node] && p!=-1){
                ap.insert(node);
            }
            children++;
            low[node] = min(low[node], low[child]);
        }
    }
    if(p == -1 && children>1) ap.insert(node);
}

int main()
{
    while(true){
        int n, m;
        cin>>n>>m;
        if(n == 0 && m == 0) break;

        for(int i=1;i<=n;i++){
            G[i].clear();
            visited[i] = 0;
        }
        ap.clear();
        timer=1;

        for(int i=0;i<m;i++){
            int a, b; 
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }

        for(int i=1;i<=n;i++){
            if(!visited[i]){
                dfs(i, -1);
            }
        }

        cout<<ap.size()<<endl;
    }

    return 0;
}