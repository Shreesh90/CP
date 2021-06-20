#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    int t; cin>>t;
    while(t--){
        vector<int> arr;
        int n; cin>>n;
        vector<int> booli;

        ll sum=0;
        int p=0;
        for(int i=0;i<n;i++){
            int temp; cin>>temp;
            arr.pb(temp);
            if(temp >= 0){
                p++;
                sum += temp;
            }
        }

        for(int i=0;i<n;i++){
            if(i < p && arr[i] < 0){
             }
            else if(i >= p && arr[i] >= 0){
               booli.pb(i);
                booli.pb(i);
            }
        }
        cout<<sum<<endl;
        cout<<booli.size()<<" ";
        for(auto it:booli) cout<<it+1<<" ";
        cout<<endl;
    }
}