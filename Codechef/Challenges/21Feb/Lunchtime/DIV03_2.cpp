#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
    ll t; cin>>t;

    while(t--){
        ll k;
        ll a[11] = {0};
        
        for(int i=1;i<=10;i++) cin>>a[i];

        cin>>k;
        int index=10;
        while(k>=0 && index>=1){
            k -= a[index--];
        }
        cout<<index+1<<"\n";

    }
}