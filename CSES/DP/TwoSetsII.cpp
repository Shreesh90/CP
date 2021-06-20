#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
long long inv;

ll power(long long x ,long long n){
    x %= mod;
    ll ans=1;
    while(n!=0){
        if(n%2==1) ans=(ans*x) %mod;
        x = x*x %mod;
        n >>= 1;
    }
    return ans;
}

ll solve(ll n, ll sum){
    
    ll t[n+1][sum+1];
    
    for(ll i=0;i<n+1;i++){
        for(ll j=0;j<sum+1;j++){
            if(i==0) t[i][j] = 0;
            if(j==0) t[i][j] = 1;
        }
    }

    for(ll i=1; i<n+1;i++){
        for(ll j=1;j<sum+1;j++){
            if(i <= j){
                t[i][j] = (t[i-1][j]%mod + t[i-1][j-i]%mod)%mod;
            } else {
                t[i][j] = t[i-1][j]%mod;
            }
        }
    }
    ll ret = t[n][sum]%mod * inv%mod; 
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    inv = power(2, mod-2);
    
    int n; 
    cin>>n;
    ll sum = ((n)*(n+1))/2;
    if(sum%2 == 1)cout<<0;
    else cout<<solve(n, sum/2);
}