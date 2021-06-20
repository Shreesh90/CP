#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t;
    while(t--){
        ll k,q;
        cin>>k>>q;

    	vector<ll> motivation;
        vector<ll> satisfaction;
        vector<ll> sum;

        int temp;
        for(int i=0;i<k;i++) {
            cin>>temp; 
            motivation.pb(temp);
        }
        for(int i=0;i<k;i++) {
            cin>>temp;
            satisfaction.pb(temp);    
        }

        sort(motivation.begin(), motivation.end());
        sort(satisfaction.begin(), satisfaction.end());

        if(k <= 100){
            for(int i=0;i<k;i++){
                for(int j=0;j<k;j++){
                    sum.pb(motivation[i] + satisfaction[j]);
                }
            }
        } else {
            ll maxi = motivation[100] + satisfaction[100];
            for(int i=0;i<k;i++){
                for(int j=0; j<k && (motivation[i]+satisfaction[j])<maxi ;j++){
                    sum.pb(motivation[i] + satisfaction[j]);
                }
            }
        }

        sort(sum.begin(), sum.end());

        for(int i=0;i<q;i++){
            int x; cin>>x;
            cout<<sum[x-1]<<endl;
        }
    }
}