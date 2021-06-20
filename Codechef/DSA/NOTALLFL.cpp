#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--){
        int n, k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];

        int diff=0, max = -1, currmax=0;
        map<int,int> freq;
        int j=0;
        for(int i=0;i<n;i++){
            freq[a[i]]++;
            if(freq[a[i]] == 1) diff++;
            while(diff == k){
                freq[a[j]]--;
                if(freq[a[j]] == 0)
                    diff--;
                j++;
            }
            currmax = i-j+1;
            if(currmax > max)
                max = currmax;
        }
        cout<<max<<"\n";

    }
}


