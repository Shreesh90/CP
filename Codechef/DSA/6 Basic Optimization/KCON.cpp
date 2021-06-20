#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll kadane(ll a[], ll size, int n){
    ll max_global = a[0];
    ll max_curr = a[0];

    for(ll i=1; i<size;i++){
        max_curr = max(a[i%n], a[i%n] + max_curr);
        max_global = max(max_curr, max_global);
    }

    return max_global;
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;

        ll a[n];
        for(int i=0; i<n;i++){
            cin>>a[i];
        }

        ll ans = kadane(a, n*k, n);
        cout<<ans<<endl;
    }
}