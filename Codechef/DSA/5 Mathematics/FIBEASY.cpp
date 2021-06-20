#include<bits/stdc++.h>
using namespace std;

const int N=2;

void mul(int ans[][N], int S[N][N],int T[N][N]){
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            // int temp = ans[i][j];
            ans[i][j] = 0;
            for(int k=0;k<N;k++){
                ans[i][j] += S[i][k] * T[k][j];
            }
            // ans[i][j] -= temp;
            // int temp2 = ans[i][j];
            // S[i][j] -= temp2;
            // T[i][j] -= temp2;
        }
    }
}

void power(int M[][N], int n, int ans[][N]){


    int I[][N] = { {1, 0},
                   {0, 1} };
    
    while(n!=0){
        I[0][0] = ans[0][0];
        I[0][1] = ans[0][1];
        I[1][0] = ans[1][0];
        I[1][1] = ans[1][1];

        if(n%2 == 1)  mul(ans, I, M);
        mul(M, M, M);
        n = n/2;
    }

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         cout<<I[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

}

int main()
{   
    int M[N][N] = { {1, 1},
                    {1, 0} };
    
    
    int I[N][N] = { {1, 0},
                    {0, 1} };
    
    int ans[N][N] = { {1, 0},
                      {0, 1} };
    // int n; cin>>n;
    // power(M, n, ans);
    
    mul(M, M, M);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }

}