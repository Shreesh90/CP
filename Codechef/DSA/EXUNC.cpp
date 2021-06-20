#include<iostream>
#include<set>
using namespace std;

int secondAction(set<int> indices, int x){
    set<int> ::iterator ans; 
    ans = indices.upper_bound(x);
    return *ans;
}

int main()
{
    int N, Q;
    cin>>N>>Q;
    int a[N+1]={0};

    for(int i=1;i<=N;i++) cin>>a[i];
    set<int> indices;

    indices.insert(1);
    for(int i=2;i<=N;i++){
        if(a[i]%a[i-1] == 0) continue;
        indices.insert(i);
    }

    set<int> ::iterator it;
    for(it=indices.begin(); it != indices.end(); it++){
        cout<<*it<<" ";
    }

    int action, x, X;
    for(int i=0;i<Q;i++){
        cin>>action;

        if(action == 1){
            cin>>x>>X;
            a[x] = X;
            // indices = firstAction(a, indices);
        }
        else{
            cin>>x;
            // set<int> ::iterator ans;
            int ans = secondAction(indices, x);
            cout<<ans<<endl;
        }
    }

}

