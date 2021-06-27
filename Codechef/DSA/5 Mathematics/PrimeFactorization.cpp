#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int prime_factor[N]; // initially false
vector<pair<int, int> > prime_factors[N];

bool square_free(int x){
    for(auto it:prime_factors[x]){
        if(it.second > 1) return 0;
    }
    return 1;
}

int main()
{
    int n; cin>>n;

    // Sieve of Erasthonese
    for(int i=2; i<=n ;i++){
        if(prime_factor[i] != 0) continue;
        prime_factor[i] = i;
        for(int j=2*i; j<=n; j += i){
            prime_factor[j] = i;
        }
    }

    // Factorization
    for(int i=2; i<=n; i++){
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

    cout<<"Prime Factorization: "<<endl;
    for(auto it: prime_factors[n]){
        cout<<it.first<<" ^ "<<it.second<<endl;
    }

    int squaref = square_free(n);
    if(squaref == 0) cout<<"Not square free.";
    else cout<<"Square free.";

}