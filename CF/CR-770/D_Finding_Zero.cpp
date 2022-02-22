#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--){
        cout.flush();
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        vector<int> A(n);

        for(int i=0;i<n;i++){
            int x;
            string a = to_string(i%n + 1);
            string b = to_string((i+1)%n + 1);
            string c = to_string((i+2)%n + 1);
            string q = "? " + a + " " + b + " " + c;
            cout<<q;
            cin>>x;
            A.push_back(x);
        }

        for(int i=0;i<n;i++){
            int a = i%n;
            int b = (i+1)%n;
            if(A[a] == A[b]){
                string x = to_string(a + 1);
                string y = to_string(b + 1);
                string ret = "! " + x + " " + y;
                cout<<ret;
                break;
            }
        }
    }
}