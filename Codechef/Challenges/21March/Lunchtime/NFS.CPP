#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main() {
    ll t; cin>>t;

    while(t--){
        ll u,v,a,s;
        cin>>u>>v>>a>>s;
        if(u == v){
            cout<<"Yes"<<endl;
        }
        else {
            float _s = (u*u - v*v)/(2*a*1.0);
            if(_s <= s) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
}