#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    
    cin.tie(0);
    cout.tie(0);
    ll t; cin>>t;

    while(t--){
        ll n, k;
        cin>>n>>k;
        if(n<k || k==0) cout<<n<<"\n";
        // else if(n == k) cout<<0<<endl;
        else {
            cout<<n%k<<"\n";
        }
    }
    return 0;
}