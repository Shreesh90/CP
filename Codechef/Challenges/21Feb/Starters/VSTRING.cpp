#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int main()
{
    int t; cin>>t;
    while(t--){
        ll n, c;
        cin>>n>>c;
        string s; cin>>s;

        vector<ll> index;
        for(ll i=0;i<s.size();i++){
            if(s[i] == '1') index.pb(i);
        }

        ll count=0;
        for(ll i=0;i+1<index.size();i++){
            if(index[i+1] - index[i] - 1 > c) count++;
        }

        if(!index.empty() and n - index.back() - 1 + index[0] > c ) count++;
        if(count <= 1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}