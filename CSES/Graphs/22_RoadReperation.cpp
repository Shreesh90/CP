#include<bits/stdc++.h>
using namespace std;
#define int long long int
struct edge{
    int a, b, w;
};

edge G[200001];
int par[100001];
int n,m,sum=0;

bool comp (edge a, edge b){
    return a.w < b.w;
}

int find(int a){
    if(par[a] == -1) return a;
    return par[a] = find(par[a]);
}

void merge(int a, int b){ 
    par[a] = b;
}

int32_t main()
{   
    memset(par, -1, sizeof(par));

    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>G[i].a>>G[i].b>>G[i].w;
    }
    sort(G, G+m, comp);

    int c=0;
    for(int i=0;i<m;i++){
        int a = find(G[i].a);
        int b = find(G[i].b);
        if(a != b){
            sum += G[i].w;
            merge(a, b);
            c++;
        }
    }

    if(c == n-1) cout<<sum;
    else cout<<"IMPOSSIBLE";
}