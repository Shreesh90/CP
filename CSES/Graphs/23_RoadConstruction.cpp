#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n, m;
int len[100001];
int par[100001];

int find(int a){
    if(a == par[a]) return a;
    return par[a] = find(par[a]);
}

int32_t main()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        par[i] = i;
        len[i] = 1;
    }

    int maxi = 1;
    int cc = n;

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;

        int pa = find(a);
        int pb = find(b);

        if(pa != pb){
            cc--;
            if(len[pa] > len[pb]) swap(pa, pb);
            len[pb] += len[pa];
            len[pa] = 0;   // Iska kuch khaas kaam nai hai
            par[pa] = pb;
            maxi = max(maxi, len[pb]);
        }

        cout<<cc<<" "<<maxi<<endl;

    }


}