#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int gcd(int a, int b){
    if(a==0) return b;
    return gcd(b%a, a);
}

int main()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> A;
        vector<int> B;
        vector<pair<int,int> > diff;

        for(int i=0;i<n;i++){
            int temp; cin>>temp;
            B.pb(temp);
            A.pb(i+1);

            if(B[i] != A[i]) diff.pb({B[i], A[i]});
        }

        int flag=0;
        if(diff.size() == 0){
            flag=1;
        }
        else {
            for(auto it: diff){
                
                int a = it.second;
                int b = it.first;
                int g = gcd(a,b);
    
                if(g == b){
                    flag=1;
                } else {
                    flag=0;
                    break;
                }
            }
        }

        if(flag==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
}