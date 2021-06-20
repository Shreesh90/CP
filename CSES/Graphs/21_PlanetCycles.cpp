#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
int visited[200001], done[200001];
vector<int> G[200001];
int teleports[200001];
int n;
int tele=0;
int prime ,f=0;
vector<int> ele;

void dfs(int node,int par,int lvl){
    visited[node] = 1;
    ele.pb(node);
    // cout<<node<<" ";
    for(int c: G[node]){
        if(!visited[c])
            dfs(c, node, lvl+1);
        else if(visited[c] & c != par){
            if(c == prime) {
                for(int x: ele){ 
                    done[x] =1;
                    teleports[x] = lvl+1;
                }
            }
            // else tele = lvl+1;
            else {
                done[prime] = 1;
                teleports[prime] = lvl+1;
            }
            return;
        }
    }
}

int32_t main()
{
    cin>>n;

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        G[i].pb(x);
    }

    for(int i=1;i<=n;i++){
        if(!done[i]){
            prime = i;
            memset(visited, 0, sizeof(visited));
            ele.clear();
            tele=0;
            dfs(i, -1, 0);
        }
    }

    for(int i=1;i<=n;i++) cout<<teleports[i]<<" ";

    // for(int i=1;i<=n;i++){
    //     prime = i;
    //     memset(visited, 0, sizeof(visited));
    //     tele=0;
    //     dfs(i, -1, 0);
    //     // cout<<tele<<" "; 
    // }
}