#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1000000000;

ll power(ll a, ll x, ll p){
    a %= p;
    ll ans=1;
    while(x!=0){
        if(x%2 == 1) ans = ((ans%p * a%p)%p + p)%p;
        a = ((a%p * a%p)%p +p)%p;
        x /= 2;
    }
    return ans;
}

ll inverse(ll a, ll p){
    return power(a, p-2, p)%p;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n; cin>>n;
    
    ll a[n+1]={1};
    ll mul[n+1]={1};

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    mul[1] = a[1]%M;
    for(int i=2;i<=n;i++){
        mul[i] = (a[i]%M * mul[i-1]%M)%M;
    }

    ll t; cin>>t;
    while(t--){
        ll l,r,m;
        cin>>l>>r>>m;
        ll ans = ( mul[r]%m * inverse(mul[l-1], m)%m )%m;
        cout<<ans<<endl;
    }
}