//Time Complexity - O(nlog(n)) (best and average case)
//                - O(n2) (Worst case)
#include<stdio.h>

void swap(int *a, int*b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int partition(int *A, int start, int end){
    int pivot = A[end];
    int partitionIndex = start;
    for(int i=start;i<end;i++){
        if(A[i] < pivot){
            swap(&A[i],&A[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(&A[partitionIndex], &A[end]);
    return partitionIndex;
}

void QuickSort(int *A,int start, int end){
    if(start >=end) return;
    int partitionIndex = partition(A, start, end);
    // printf("%d\n", partitionIndex);
    // for(int i=0;i<5;i++)
    //     printf("%d ",A[i]);
    // printf("\n");
    QuickSort(A,start, partitionIndex-1);
    QuickSort(A, partitionIndex+1, end);
}

int main()
{
    int A[5] = {4,5,2,1,3};  // 1,2,3,4,5
    QuickSort(A,0,4);

    for(int i=0;i<5;i++)
        printf("%d ",A[i]);
}



