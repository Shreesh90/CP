#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin>>t;

    while(t--){
        ll n; cin>>n;
        string s;
        cin>>s;
        
        ll l = s.length();
        ll count = 0;
        for(ll i=l-1; i>=0;i--){
            if(s[i] == ')' )  count++;
            else break;
        }

        ll counter = l-count;

        if(count > counter) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}

