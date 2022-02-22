// The array inceases and then decreases. 
// Find the Maximium element

#include<bits/stdc++.h>
using namespace std;

int bs(int a[], int lo, int hi){
    int index=-1;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;

        if(mid == 0 || a[mid] > a[lo]){
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
    int a[8] = {4,5,6,7,0,1,2,3};
    int b[4] = {4,3,2,1};
    int c[4] = {2,3,4,5};

    int index = bs(a, 0, 7);
    cout<<index;

}

