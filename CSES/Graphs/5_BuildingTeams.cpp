#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> G[100001];
int visited[100001];
int team[100001];

bool dfs(int x, int c){
    visited[x]=1;
    team[x]=c;
    for(int ch: G[x]){
        if(!visited[ch]){
            if(dfs(ch, c^1) == false) return false;
        } else {
            if(team[x] == team[ch]) return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }

    bool ret = true;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            ret = ret && dfs(i, 1);
        }
    }

    if(ret){
        for(int i=1;i<=n;i++){
            if(team[i]) cout<<team[i]<<" ";
            else cout<<2<<" ";
        }
    } else {
        cout<<"IMPOSSIBLE";
    }
}
