#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        if(k==1){
            cout<<"YES\n";
            int num=1;
            while(n--){
                cout<<num<<"\n";
                num++;
            }
        }
        else if(n==1){
            cout<<"NO\n";
        }
        else {
            if(n%2 == 1) cout<<"NO\n";
            else {
                cout<<"YES\n";
                int A[n][k];
                int num=1;
                for(int i=0;i<k;i++){
                    for(int j=0;j<n;j++){
                        A[j][i] = num++;
                    }
                }
                for(int i=0;i<n;i++){
                    for(int j=0;j<k;j++){
                        cout<<A[i][j]<<" ";
                    }
                    cout<<"\n";
                }
            }
        }

    }
}