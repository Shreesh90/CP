#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        ll n,k,d;
        cin>>n>>k>>d;
        ll a[n];
        ll sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum += a[i];
        }

        ll days = sum/k;
        int ans;
        if(days<d) ans = days;
        else ans = d;

        cout<<ans<<endl;

    }
}
