#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n";
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--){
        ll n,m,k;
        cin>>n>>m>>k;
        ll ans = 0;
        for(ll i=1;i<=n;i++){
            if(min(i, m)%2 == 1){
                ans ^= k + i + 1;
            }
        }

        for(int i=2;i<=m;i++){
            if(min(m-i+1, n) %2 == 1){
                ans ^= k+i+n;
            }
        }

        cout<<ans<<endl;

    }
}