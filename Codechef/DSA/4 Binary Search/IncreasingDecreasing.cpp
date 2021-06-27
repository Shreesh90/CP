// The array inceases and then decreases. 
// Find the Maximium element

#include<bits/stdc++.h>
using namespace std;

int bs(int a[], int lo, int hi){
    int index=-1;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;

        if(mid == 0 || a[mid] > a[mid-1]){
            index=mid;
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    return index;
}

int main(){
    int a[11] = {2,3,4,6,9,12,11,8,6,4,1};
    int b[4] = {4,3,2,1};
    int c[4] = {2,3,4,5};

    int index = bs(a, 0, 10);
    cout<<index;

}

