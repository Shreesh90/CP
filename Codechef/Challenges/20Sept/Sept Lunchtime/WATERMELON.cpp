#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> A;

        int base=0;
        int sum=0;
        for(int i=0;i<n;i++){
            int temp; cin>>temp;
            A.pb(temp);
            sum += temp;
            base += (i+1);
        }
    
        int flag;
        if(sum < 0){
            flag=0;
        }

        else if(sum == 0){
            flag=1;
        }

        else{
            flag=1;
        }
        
        if(flag==0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }
}