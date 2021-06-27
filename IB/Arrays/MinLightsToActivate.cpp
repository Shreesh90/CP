#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> A = {1, 1, 1, 1, 1, 0, 0};
    int B=3;

    int l=0;
    int r=0;
    int ans=0;
    int ind=0;

    while(r < A.size()){
        for(int i=ind;i<A.size();i++){
            if(!A[i]) continue;
            if(i-B+1 <= l and i+B-1 >r){
                r = i+B-1;
                ind = i;
            }
        }
        if(l==r) break;
        l = r;
        ans++;
    }
    cout<<l<<" "<<r;
    if(l==r and l<A.size()-1) cout<<-1;
    else cout<<ans;
    // return ans;
    

}
