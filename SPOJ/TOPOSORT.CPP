#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> G[10001];
vector<int> res;
int in[10001];

void kahn(int n){
    // To get lexicographically smallest ordering - priority queue
    priority_queue<int, vector<int>, greater<int> > q;

    for(int i=1;i<=n;i++){
        if(in[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int curr = q.top();
        res.pb(curr);
        q.pop();
        for(int node: G[curr]){
            in[node]--;
            if(in[node] == 0) q.push(node);
        }
    }

    if(res.size() == n){
        for(int x: res) cout<<x<<" ";
    }
    else {
        cout<<"Sandro fails.";
    }
}

int main() {
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        G[x].pb(y);
        in[y]++;
    }

    kahn(n);
}