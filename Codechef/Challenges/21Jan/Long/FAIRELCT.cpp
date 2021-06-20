#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

void swapping(ll mina, ll maxb, ll indexa, ll indexb, vector<int> &a, vector<int> &b){
    a[indexa] = maxb;
    b[indexb] = mina;
    return;
}

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;

        vector<int> a,b;
        ll suma=0, sumb=0;
        for(int i=0;i<n;i++){
            int x; cin>>x;
            a.pb(x);
            suma += x;
        }
        for(int i=0;i<m;i++){
            int x; cin>>x;
            b.pb(x);
            sumb += x;
        }
        ll swaps = 0;


        for(int i=0;i<n;i++){
            if(suma > sumb) break;

            ll mina = *min_element(a.begin(), a.end());
            ll maxb = *max_element(b.begin(), b.end());

            int indexa = find(a.begin(), a.end(), mina) - a.begin(); 
            int indexb = find(b.begin(), b.end(), maxb) - b.begin();

            swapping(mina, maxb, indexa, indexb, a, b);
            swaps++;

            suma += (maxb-mina);
            sumb -= (maxb-mina);
        }

        if(suma > sumb){
            cout<<swaps<<endl;
        } else {
            cout<<-1<<endl;
        }

    }
}
