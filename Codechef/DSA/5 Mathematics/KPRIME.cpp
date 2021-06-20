#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int prime_factor[N]; 
int counter[6][N] = {};
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

    for(int p=2; p<=N; p++){
        for(int k=1; k<=5; k++){
            if(prime_factors[p].size() == k){
                counter[k][p] = counter[k][p-1] + 1;
            } else {
                counter[k][p] = counter[k][p-1];
            }
        }
    }

    int t; cin>>t;
    while(t--)
    {
        int a,b,k;
        cin>>a>>b>>k;
        int ans = counter[k][b] - counter[k][a-1];
        cout<<ans<<endl;
        
    }
}