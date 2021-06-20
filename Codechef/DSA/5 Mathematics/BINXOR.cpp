#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1000000007;

ll fact[100001];

void factorial(){
    fact[0] = fact[1] = 1;
    for(int i=2; i<=100001; i++){
        fact[i] = (i*fact[i-1])%M;
    }
}

ll power(ll a, ll x){
    a = a%M;
    ll ans=1;
    while(x!=0){
        if(x&1) ans = ((ans%M * a%M)%M + M)%M;
        a = ((a%M * a%M)%M + M)%M;
        x >>= 1;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    factorial();
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        string a,b;

        cin>>a>>b;
        ll a0=0, a1=0, b0=0, b1=0;

        for(int i=0;i<n;i++){
            if(a[i] == '0'){
                a0++;
            } else {
                a1++;
            }

            if(b[i] == '0'){
                b0++;
            } else {
                b1++;
            }
        }

        ll min1 = abs(a1-b1);
        ll max1 = min(a0, b1) + min(a1, b0);

        ll sum=0;
        for(int r=min1; r<=max1; r+=2){
            ll nf = fact[n]%M;
            ll rf = fact[r]%M;
            ll n_rf = fact[n-r]%M;

            // ll inv1 = power(rf, M-2)%M;
            // ll inv2 = power(n_rf, M-2)%M;

            ll b = power(rf * n_rf, M-2) % M;
            // cout<<nf<<" "<<rf<<" "<<n_rf<<" "<<b<<endl;
            if(r==0 || r==n) sum++;
            else sum = (sum + (nf%M * b%M)%M)%M;   
        }
        cout<<sum<<endl;
    }
}