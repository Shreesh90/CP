#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

const ll N = 1e8+5;
vector<ll> numbers(N,0);
vector<ll> squares;

int main()
{ 
    squares.pb(1);
    for(ll i=2;i<=N;i++){
        if(numbers[i] == 1){
            squares.pb(i);
            continue;
        }
        ll temp = i*i;
        for(ll j=temp; j<=N; j *= temp){
            numbers[j] = 1;
        }
    }

    // for(auto it:squares) cout<<it<<" ";

    int t; cin>>t;
    while(t--){
        ll n; cin>>n;

        ll lo=0, hi=squares.size()-1;

        ll ans=-1;
        while(lo<hi){
            ll mid = lo + (hi-lo)/2;
            ll sq1 = squares[mid];
            ll  diff = squares[mid+1] - squares[mid];
            if(n < diff) hi=mid;
            else if(n > diff) lo=mid+1;
            else{
                ans = sq1;
                break;
            }
        }
        cout<<ans<<endl;
    }


}
