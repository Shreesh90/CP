#include<stdio.h>

void insertionSort(int *a, int n){
    for(int i=0;i<n-1;i++){
        int value = a[i+1];
        for(int j=i;j>=0;j--){
            if(a[j] > value){
                a[j+1] = a[j];
                a[j] = value;
            }
        }
    }
}

int main()
{
    int a[5] = {5,4,3,2,1};
    insertionSort(a,5);

    for(int i=0;i<5;i++){
        printf("%d ", a[i]);
    }
}

