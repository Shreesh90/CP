#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vector<ll> A(n);

        for(ll i=0;i<n;i++) cin>>A[i];

        vector<pair<ll, ll> > mini(n), maxi(n);

        mini[n-1] = make_pair(A[n-1], n-1);
        ll temp = A[n-1];

        for(ll i=n-2;i>=0;i--){
            if(A[i] < temp){
                mini[i] = make_pair(A[i], i);
                temp = A[i];
            }
            else mini[i] = mini[i+1];
        }

        maxi[n-1] = make_pair(A[n-1], n-1);
        temp = A[n-1];

        for(ll i=n-2;i>=0;i--){
            if(A[i] > temp){
                maxi[i] = make_pair(A[i], i);
                temp = A[i];
            }
            else maxi[i] = maxi[i+1];
        }

        vector<tuple<ll, ll, ll> > ans;
        ll ret = 0;

        for(ll i=n-3;i>=0;i--){
            if(A[i] > A[i+1]){
                if(mini[i+1].second < maxi[i+1].second){
                    ret++;
                    ans.push_back(make_tuple(i+1, mini[i+1].second+1, maxi[i+1].second+1));
                    A[i] = mini[i+1].first - maxi[i+1].first;
                }
                else {
                    ret = -1;
                    break;
                }
            }
        }
        if(n>3){
            if(A[n-2] > A[n-1]) ret = -1;
        }
        if(ret == 0 || ret == -1) cout<<ret<<"\n";
        else {
            cout<<ans.size()<<"\n";
            for(ll i=0;i<ans.size();i++){
                cout<< get<0>(ans[i])<<" ";
                cout<< get<1>(ans[i])<<" ";
                cout<< get<2>(ans[i])<<"\n";
            }
        }
    }
}