#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int maxN = 30;
int LCA[200001][30];

int32_t main()
{
    int n, q;
    cin>>n>>q;

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        LCA[i][0] = x;
    }

    for(int j=1;j<maxN;j++){
        for(int i=1;i<=n;i++){
                int pa = LCA[i][j-1];
                LCA[i][j] = LCA[pa][j-1];
        }
    }

    while(q--){
        int x, k;
        cin>>x>>k;
        for(int i=0;i<maxN;i++){
            if(k & (1<<i)) x=LCA[x][i];
        }
        cout<<x<<endl;
    }
}