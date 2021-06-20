//Time Complexity - nlog(n) (Worst case) 
//Space COmplexity = O(n)
// Not In-place Algorithm
#include<stdio.h>

void merge(int *A, int *Left, int *Right, int nL, int nR){
    int i=0,j=0,k=0;
    while(i < nL && j < nR){
        if(Left[i] <= Right[j]){
            A[k] = Left[i];
            k++;i++;
        }
        else{
            A[k] = Right[j];
            k++;j++;
        }
    }
    while(i<nL){
        A[k] = Left[i];
        k++;
        i++;
    }
    while(j<nR){
        A[k] = Right[i];
        k++;
        j++;
    } 
}

void mergeSort(int *A, int n){
    if(n < 2) return;
    int mid = n/2;
    int nL = mid; int Left[nL];
    int nR = n-mid; int Right[nR];
    for(int i=0;i<mid;i++)
        Left[i] = A[i];
    for(int i=mid;i<n;i++)
        Right[i-mid] = A[i];
    mergeSort(Left, nL);
    mergeSort(Right, nR);
    merge(A,Left,Right,nL,nR);
}

int main()
{
    int A[5] = {5,4,3,2,1};
    
    mergeSort(A, 5);

    for(int i=0;i<5;i++)
        printf("%d ", A[i]);

}

