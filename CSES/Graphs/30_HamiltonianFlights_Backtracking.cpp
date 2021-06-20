#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int G[21][21];
int n, m;
int paths[21];
int cc=0;

void nextVertex(int ind){
    // cout<<ind<<" ";
    while(true){
        int f=0;
        paths[ind] = (paths[ind] + 1)%(n+1);
        if(ind == n and  paths[ind] != n) continue;
        if(paths[ind] == 0) return;
        if(G[paths[ind-1]][paths[ind]] == 0) continue;
        for(int j=1; j<ind;j++){ 
            if(paths[j] == paths[ind]) {f=1; break;}
        }
        if(f) continue;
        // if(ind<n or (ind == n )) return;
        return;
    }
}

void hamiltonian(int x){
    while(true){
        nextVertex(x);
        if(paths[x]==0) return;
        if(x == n){
            // for(int z=1;z<=n;z++) cout<<paths[z]<<" ";
            // cout<<endl;
            cc = (cc%mod + 1)%mod;
        }
        else {
            hamiltonian(x+1);
        }
    }
}

int32_t main()
{   fast;
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int a, b;
        cin>>a>>b;
        G[a][b] = 1;
    }

    paths[1] = 1;
    hamiltonian(2);
    cout<<cc;
}
