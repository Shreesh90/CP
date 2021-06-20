#include<bits/stdc++.h>
using namespace std;

int a[10][10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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

            if(ans%2){
                swap(a[i][0], a[0][i]);
            }

            if(a[i][0] < a[0][i]){
                ans++;
            }
        }
        cout<<ans<<endl;

    }
}

