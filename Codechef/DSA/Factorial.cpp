#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll t,x;
    cin>>t;
    ll ans = 0;
    for(int i=0;i<t;i++){
        ans = 0;
        cin>>x;
        while(x != 0){
            x = x/5;
            ans += x;
        }
        cout<<ans<<endl;
    }
}