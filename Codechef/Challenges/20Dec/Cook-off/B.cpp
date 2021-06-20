#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long maxi = 1000000000000000000;

bool div(ll n){
    ll temp = n;
    while(n != 0){
        if(temp % (n%10)){
            n /= 10;
        } else {
            return 0;
        }
    }
    return 1;
}

ll bin(ll n){
    ll lo = n;
    ll hi = maxi;

    ll ans;
    while(lo<=hi){
        ll mid = lo + (hi - lo)/2;
        bool check = div(mid);
        if(check){
            ans = mid;
            hi = mid-1;
        } else {
            hi = mid-1;
        }
    }

    return ans;

}

int main()
{
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        ll ans = bin(n);
        cout<<ans<<endl;
    }
}