#include<bits/stdc++.h>
using namespace std;

int main()
{
    int A;
    // cin>>A;
    A=5;

    int res[1000]={0};

    res[0] = 1;
    int res_size = 1;
    
    for(int i=1;i<=A;i++){
        int carry = 0;
        for(int j=0;j<res_size;j++){
            int val = (res[j]*i) + carry;

            res[j] = val%10;
            carry = val/10;
        }

        while(carry){
            res[res_size] = carry%10;
            res_size++;
            carry = carry/10;
        }

    }

    string ret = "";
    for(int i = res_size-1;i>=0;i--){
        ret += to_string(res[i]);
    }

    cout<<ret;
}