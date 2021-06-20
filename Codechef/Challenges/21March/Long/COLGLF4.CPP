#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    int t; cin>>t;

    while(t--){
        int N,E,H,A,B,C;
        cin>>N>>E>>H>>A>>B>>C;
        int ret = INT_MAX;

        for(int i=0;i<=N;i++){
            if(E < i or H < i) break;

            int o = (E-i)/2;
            int m = (H-i)/3;

            if(i + o + m < N) continue;

            int maxo, maxm;
            if(A < B){
                maxo = min(N-i, o);
                maxm = N - i - maxo;
            }
            else {
                maxm = min(N-i, m);
                maxo = N - i - maxm;
            }

            int price = i*C + maxo*A + maxm*B;
            ret = min(price, ret);    
        }
        if(ret == INT_MAX) ret = -1;
        
        cout<<ret<<"\n";
    }

    return 0;
}