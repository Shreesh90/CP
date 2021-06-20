#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int, int>
vector<pair<int, int> > G[101];
vector<int> dist(101, INT_MAX);
int n, e ,t ,r;

int main(){
    cin>>n>>e>>t>>r;
    for(int i=0;i<r;i++){
        int a,b,w;
        cin>>a>>b>>w;
        G[b].pb({a, w});
    }    

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, e});
    dist[e] = 0;

    while(!pq.empty()){
        int curr = pq.top().second;
        int currd = pq.top().first;
        pq.pop();
        for(auto it: G[curr]){
            int d = currd + it.second;
            if(d < dist[it.first]){
                dist[it.first] = d;
                pq.push({dist[it.first], it.first});
            }
        }
    }

    int count=0;
    for(int i=1;i<=n;i++){
        if(dist[i] <= t) count++;
    }

    cout<<count;
}

