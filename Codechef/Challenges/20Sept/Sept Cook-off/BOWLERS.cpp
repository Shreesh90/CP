#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;

    while(t--){
        int n,k,l;
        cin>>n>>k>>l;

        vector<int> overs(n,0);
        vector<int> count(k, l);    

        int flag = 1;
        for(int i=0; i<n;i++){
            if(count[i%k] > 0){
                overs[i] = i%k + 1;
                count[i%k]--;
                
            } else {
                int sum = accumulate(count.begin(), count.end(), 0);
                if(sum == 0){
                    flag=0; break;
                }
            }
            if(overs[i] == overs[i-1]){
                flag=0; break;
            }
        }

        if(flag==1){
            for(auto it: overs) cout<<it<<" ";
        } else {
            cout<<-1;
        }

        cout<<endl;

    }
}