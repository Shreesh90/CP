#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;

    while(t--){
        int n,k,x,y;
        cin>>n>>k>>x>>y;

        bool cities[n] = {false};
        cities[x] = true;

        bool ans = false;
        for(int i=0;i<n;i++){
            int next = (x%n + k%n)%n;
            cities[next] = true;
            if(x==y){
                ans=true;
                break;
            }
            x += k;

            if(next == y){
                ans = true;
                break;
            }
        }

        if(ans==false) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;


    }
}