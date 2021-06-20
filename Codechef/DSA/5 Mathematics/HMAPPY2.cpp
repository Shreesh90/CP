#include<bits/stdc++.h>
using namespace std;
#define ll long long
int gcd(ll a, ll b){
    if(a==0) return b;
    return gcd(b%a, a);
}

int lcm(ll a, ll b){
    ll g = gcd(a,b);
    return (a/g)*b;
}

int main()
{
    int t; cin>>t;

    while(t--)
    {
        ll n,a,b,k;
        cin>>n>>a>>b>>k;

        ll m = lcm(a,b);
        ll appy = n/a;
        ll chef = n/b;
        ll common = n/m;

        ll ans = (appy+chef) - 2*common;
        if(ans >= k) cout<<"Win"<<endl;
        else cout<<"Lose"<<endl;
        

    }
}

