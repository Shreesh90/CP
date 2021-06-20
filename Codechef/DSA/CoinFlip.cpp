#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,g,i,n,q;

    cin>>t;

    while(t--){
        cin>>g;
        
        while(g--){
            cin>>i>>n>>q;
            int heads,tails;
            if(n%2 == 0){
                if(i == 1){
                    heads = n/2;
                    tails = n/2; 
                }
                else if(i==2){
                    heads = n/2;
                    tails = n/2;
                }
            }
            if(n%2 != 0){
                if(i == 1){
                    heads = n/2;
                    tails = n/2+1;
                }
                else if(i == 2){
                    tails = n/2;
                    heads = n/2+1;
                }
            }
            if(q == 1)
                cout<<heads<<"\n";
            else if(q==2)
                cout<<tails<<"\n";
        }
        
    }
}