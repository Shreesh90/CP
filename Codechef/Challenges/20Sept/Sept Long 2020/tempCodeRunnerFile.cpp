#include<bits/stdc++.h>
using namespace std;

int a[10][10];

int main()
{
    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }

        int ans=0;

        for(int i=n-1;i>=0;i--){
            int x,y;
            x = a[i][0];
            y = a[0][i];

            if(ans%2 == 1){
                swap(a[i][0], a[0][i]);
            }

            if(x < y){
                ans++;
            }
        }
        cout<<ans<<endl;

    }
}