#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = { 32592, 18763, 1656, 17411, 6360, 27625, 20538, 21549, 6484, 27596 };
    int n = a.size();
    int maxright[1001] = {0};
    
    for(int i=n-1;i>=0;i--){
        maxright[i] = max(a[i], maxright[i+1]);
    }

    set<int> minleft;
    minleft.insert(a[0]);

    int ans = INT_MIN;
 
    for(int i=1;i<n-1;i++){
        if(maxright[i+1] > a[i]){
            auto it = minleft.lower_bound(a[i]);
            --it;
            ans = max(ans, *it + a[i] + maxright[i+1]);
            // cout<<ans<<" ";
            minleft.insert(a[i]);
        }
    }
    cout<<ans;
}