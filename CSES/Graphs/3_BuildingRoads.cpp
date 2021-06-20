#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> G[100001];
int visited[100001];
vector<int> cc[100001];
int cnt=0;

void dfs(int x){
    visited[x] = 1;
    cc[cnt].pb(x);

    for(int v: G[x]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    memset(visited, 0, sizeof(visited));

    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cnt++;
            dfs(i);
        }
    }

    cout<<cnt-1<<endl;

    for(int i=1;i<=cnt-1;i++){
        cout<<cc[i][0]<<" "<<cc[i+1][0]<<endl;
    }
    
}