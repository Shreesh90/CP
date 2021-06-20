#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llf float
#define endl "\n"

int main() {
    int t; cin>>t;
    while(t--){
       llf x,r,m;
       cin>>x>>r>>m;
       r = (r*60 - x)*2 + x;
       m *= x;
       if(r <= m) cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
    }
}