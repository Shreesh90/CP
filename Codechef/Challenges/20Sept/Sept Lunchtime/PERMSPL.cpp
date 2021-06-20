#include<bits/stdc++.h>
using namespace std;
int inv=0;

void merge(vector<int> &a, vector<int> &b, vector<int> &sorted){
    int aptr=0, bptr=0;

    while(aptr < a.size() && bptr < b.size()){
        if(a[aptr] <= b[bptr]){
            sorted.push_back(a[aptr++]);
        } else {
            inv += a.size() - aptr;
            sorted.push_back(b[bptr++]);
        }
    }

    while(aptr < a.size()) sorted.push_back(a[aptr++]);
    while(bptr < b.size()) sorted.push_back(b[bptr++]);

    return;
}

void merge_sort(int a[], int l, int u){
    if(l==u) return;
    int mid = (l+u)/2;
    merge_sort(a, l, mid);
    merge_sort(a, mid+1, u);

    vector<int> b, c, sorted;
    for(int i=l;i<=mid;i++) b.push_back(a[i]);
    for(int i=mid+1;i<=u;i++) c.push_back(a[i]);

    merge( b, c, sorted);
    return;
}

int main()
{
    int t; cin>>t;
    while(t--){
        int inv1,inv2;
        int n; cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int flag=0;
        for(int i=0;i<n-1;i++){
            inv=0;
            merge_sort(a, 0, i);
            inv1 = inv;
            inv=0;
            merge_sort(a, i+1, n-1); 
            inv2 = inv;
            if(inv1==inv2){
                flag=1;
            }
            // cout<<inv1<<" "<<inv2<<endl;
        }

        if(flag==1 || n==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
} 

