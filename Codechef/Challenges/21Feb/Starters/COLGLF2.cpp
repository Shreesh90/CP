#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t; cin>>t;
    while(t--){
        ll s; cin>>s;
        ll Q[s];
        ll time = 0;
        for(ll i=0;i<s;i++) {
            cin>>Q[i];
            time += Q[i];
        }
        
        for(ll i=0;i<s;i++){
            ll e; cin>>e;
            ll E[e];
            for(ll j=0;j<e;j++){
                cin>>E[j];
                // if(j==0) time += E[j];
                time += (E[j] - Q[i]);
            }

        }
    
        cout<<time<<endl;
    }
    return 0;
}