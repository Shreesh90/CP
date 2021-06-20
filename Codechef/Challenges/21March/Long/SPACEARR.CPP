#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        ll a[n+1];
        int ret;
        
        ll d=0;
        for(ll i=1;i<=n;i++) cin>>a[i];

        sort(a+1, a+n+1);

        for(ll i=1;i<=n;i++){
            int td = i - a[i];
            if(td < 0){
                d = td;
                break;
            }
            d += td;
        }
            
        if(d<=0){
            ret = 2;
        } else {
            if(d%2 == 1){
                ret = 1;
            } 
            else if(d%2 == 0){
                ret = 2;
            }
        }
        if(ret == 1) cout<<"First\n";
        else cout<<"Second\n";
    }
}
