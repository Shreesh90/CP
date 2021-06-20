#include<bits/stdc++.h>
using namespace std;

int val=0;

void merge(vector<int> &a, vector<int> &b, int R){
    int aptr=0, bptr=0;

    while(aptr < a.size() && bptr < b.size()){
        if(a[aptr] <= b[bptr]){

            if(b[bptr] >= R) {
                val += R;
                b[bptr++] -= R;
            }
            else {
                val += b[bptr];
                b[bptr++] = 0;
            }
            // aptr++;

            // sorted.push_back(a[aptr++]);
        } else {

            if(a[aptr] >= R) {
                val += R;
                a[aptr++] -= R;
            }
            else {
                val += a[aptr];
                a[aptr++] = 0;
            }
            // bptr++;
            // sorted.push_back(b[bptr++]);
        }
    }

    // while(aptr < a.size()) sorted.push_back(a[aptr++]);
    // while(bptr < b.size()) sorted.push_back(b[bptr++]);

    return;
}

void merge_sort(int a[], int l, int u, int R){
    cout<<l<<" "<<u<<endl;
    if(l==u) return;
    int mid = (l+u)/2;
    merge_sort(a, l, mid, R);
    merge_sort(a, mid+1, u, R);

    vector<int> b, c; // sorted;
    for(int i=l;i<=mid;i++) b.push_back(a[i]);
    for(int i=mid+1;i<=u;i++) c.push_back(a[i]);

    merge( b, c, R);

    // for(int i=0;i<sorted.size();i++){
    //     a[l+i] = sorted[i];
    // }
    return;
}


int main()
{
    int n,R;
    cin>>n>>R;

    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    merge_sort(a, 0, n-1, R);

    cout<<val;

    return 0;
}

