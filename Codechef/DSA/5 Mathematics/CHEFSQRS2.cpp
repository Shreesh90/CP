#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t;

    while(t--){
        ll n; cin>>n;

        ll ans=10000000000000000;
        int flag=0;
        for(int i=1; i*i<=n; i++){
            if(n%i == 0){
                ll a = i;
                ll b = n/i;
                ll y = (b+a)/2;
                ll x = (b-a)/2;
                
                if(x>y) swap(x,y);
                
                ll diff = y*y - x*x;
                if(diff == n && x!=0 && y!=0){
                    ans = min(ans, x*x);
                    flag=1;
                } 
            }
        }
        if(flag==0) cout<<-1<<endl;
        else cout<<ans<<endl;
    }   
}
