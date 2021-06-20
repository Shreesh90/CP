#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int w[n+1], l[n+1], ind[n+1];

        for(int i=1;i<=n;i++){
            cin >> w[i];
            ind[w[i]] = i;
        }

        for(int i=1; i<=n;i++){
            cin >> l[w[i]];
        }

        int ans=0, hits;

        if(ind[2] <= ind[1]){
            hits = ceil(float(ind[1] - ind[2] + 1) / l[2]);
            ans += hits;
            ind[2] += hits*l[2];
        }

        if(n > 2){    
            if(ind[3] <= ind[2]){
                hits = ceil(float(ind[2] - ind[3] + 1) / l[3]);
                ans += hits;
                ind[3] += hits*l[3];
            }
        }

        if( n> 3){            
            if(ind[4] <= ind[3]){
                hits = ceil(float(ind[4] - ind[3] + 1) / l[4]);
                ans += hits;
                ind[4] += hits*l[4];
            }
        }

        cout<<ans<<endl;
    }

}