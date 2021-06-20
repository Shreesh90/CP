#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> G[100001];
vector<int> res;
int in[100001];

void kahn(int n){
    queue<int> q;
    
    for(int i=1;i<=n;i++){
        if(in[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int curr = q.front();
        res.pb(curr);
        q.pop();
        for(int c: G[curr]){
            in[c]--;
            if(in[c] == 0) q.push(c);
        }
    }
    if(res.size() == n)
        for(int x: res) cout<<x<<" ";
    else cout<<"IMPOSSIBLE";
}

int32_t main()
{
    int n, m;
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        G[x].pb(y);
        in[y]++;
    }

    kahn(n);
    
}
