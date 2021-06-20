#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int main(){
    int t; cin>>t;

    while(t--){
        ll n, x;
        cin>>n>>x;
        ll s, r;
        map<ll, ll, greater <ll> > mp;
        while(n--){
            cin>>s>>r;
            mp.insert({r, s});
        }

        for(auto it: mp){
            if(it.second <= x){ 
                cout<<it.first<<endl;
                break;
            }
        }
    }
    return 0;
}