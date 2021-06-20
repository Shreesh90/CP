#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll t; cin>>t;
    while(t--){
        ll k;
        map<int, ll> mp;
        
        for(int i=0;i<10;i++){
            ll x; cin>>x;
            if(x != 0) mp[i] = x;
        }

        cin>>k; 
        map<int, ll>::reverse_iterator it;
        for(it = mp.rbegin(); it!= mp.rend(); it++){
            if(it->second > k){
                cout<<it->first + 1<<"\n";
                break;
            } 
            else if (it->second == k) {
                it++;
                cout<<it->first + 1<<"\n";
            } else {
                k -= it->second;
                it->second = 0;
            }
        }
    }
    return 0;
}