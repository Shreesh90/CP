// DIVIDE AND CONQUER
// The Logic is - If a problem of an array can be solved with only one element
// If you have two halves with the problem sollved, can you solve the problem for the combines part?
// MERGE SORT
// Divide and conquer has two parts - the divide and the conquer
// The conquer part takes O(N)
// Total log(N) division 
// Overall algorithm takes O(N.logN)
 
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
            // inv++;
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

    for(int i=0;i<sorted.size();i++){
        a[l+i] = sorted[i];
    }
    return;
}

int main()
{
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    merge_sort(a, 0, n-1);

    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    cout<<inv;
} 

