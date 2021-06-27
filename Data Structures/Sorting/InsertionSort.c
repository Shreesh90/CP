#include<stdio.h>

void insertionSort(int *a, int n){
    for(int i=1;i<n;i++){
        int value = a[i];
        for(int j=i-1;j>=0;j--){
            if(a[j] > value){
                a[j+1] = a[j];
                a[j] = value;
            }
        }
    }
}

int main()
{
    int a[5] = {4,5,1,3,2};
    insertionSort(a,5);

    for(int i=0;i<5;i++){
        printf("%d ", a[i]);
    }
}

