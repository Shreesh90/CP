#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t;

    while(t--){
        ll n,m,x,y;
        cin>>n>>m>>x>>y;
        n--;
        m--;
    
        ll rn = (n)%x;
        ll rm = (m)%y;

        if(n==1 && m==1){
            cout<<"Chefirnemo"<<endl;
            continue;
        }
        else if( (rn==0 && rm==0) || (rn==1 && rm==1) ){
            cout<<"Chefirnemo"<<endl;
            continue;
        } 
        else if( (n==1 && rm==1) || (rn==1 && m==1) ){
            cout<<"Chefirnemo"<<endl;
            continue;
        }
        // else if( (n==0 && rm==0) || (rn==0 && m==0) ){
        //     cout<<"Chefirnemo"<<endl;
        //     continue;
        // }
        else {
            cout<<"Pofik"<<endl;
        }

    }

}