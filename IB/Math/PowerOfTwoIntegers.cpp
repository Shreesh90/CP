#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long int A = 1024000000;
    // int A = 500;

    // vector<long long int> prime_factor(A+1, 0);
    map<int,int> prime_factor;

    cout<<"P start\n";
    for(int i=2;i*i<=A;i++){
        if(prime_factor[i] != 0) continue;
        prime_factor[i] = i;
        for(int j=2*i;j<=A;j+=i){
            prime_factor[j] = i;
        }
    }

    cout<<"P end\n";


    map<int, int> mp;
    while(A!=1){
        mp[prime_factor[A]]++;
        A = A/prime_factor[A];
    }

    vector<pair<int,int>> factors;

    cout<<"Before";
    for(auto it: mp){
        factors.push_back(it);
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<"After";

    if(factors.size() == 1 and factors[0].second != 1) cout<<"YES";
    else cout<<"NO";

    for(int i=0;i<factors.size()-1;i++){
        if(factors[i].second !=  factors[i+1].second) cout<<"YES";
        if(factors[i].second == 1 or factors[i+1].second == 1) cout<<"NO";
    }
    cout<<"YES";

}