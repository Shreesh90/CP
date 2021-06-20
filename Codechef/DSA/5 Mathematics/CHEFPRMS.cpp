#include<bits/stdc++.h>
using namespace std;

const int N = 210;
int prime_factor[N]; // initially false
vector<pair<int, int> > prime_factors[N];

int main()
{
    for(int i=2; i<=N ;i++){
        if(prime_factor[i] != 0) continue;
        prime_factor[i] = i;
        for(int j=2*i; j<=N; j += i){
            prime_factor[j] = i;
        }
    }

    for(int i=2; i<=N; i++){
        int x = i;
        map<int, int> M;
        while(x != 1){
            M[prime_factor[x]]++;
            x = x / prime_factor[x];
        }
        for(auto v: M){
            prime_factors[i].push_back(v);
        }
    }

    vector<int> semiprimes;

    for(int i=2; i<=N;i++){
        int sum=0;
        for(auto it: prime_factors[i]){
            sum += it.second;
        }
        if(prime_factors[i].size()==2 && sum==2){
            semiprimes.push_back(i);
        }
    }

    // for(auto t: semiprimes) cout<<t<<" ";

    int t; cin>>t;

    while(t--){
        int n; cin>>n;

        int num;
        int index=1000;
        int lo=0,hi=semiprimes.size()-1;
        
        while(lo<=hi){
            int mid = (lo+hi)/2;
            int vmid = semiprimes[mid];    
            if(vmid >= n){
                hi = mid-1;
                index = min(mid, index);
            } else {
                lo = mid+1;
            }
        }
        int lb = index;
        cout<<semiprimes[lb];

        int flag=0;
        for(int i=0;i<=lb;i++){
            int a = semiprimes[i];
            int b = n-a;
            auto it = find(semiprimes.begin(), semiprimes.end(), b);
            if(it != semiprimes.end()){
                flag=1;
                break;
            }
        }
        if(flag == 1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        
    }


}
