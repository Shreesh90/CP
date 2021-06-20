// Time Complexity - O(n^2)
#include<stdio.h>

void swap(int* a, int i, int j){
    int t;
    t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void selectionSort(int *a, int n){
    int var=0;
    for(int i=0;i<n-1;i++){
        int min = 100000;
        for(int j=i;j<n;j++){
            if(a[j] < min){
                min = a[j];
                var = j;
            }
        }
        swap(a,i,var);
    }
}

int main()
{
    int a[5] = {4,2,6,0,7};
    selectionSort(a, 5);

    for(int i=0;i<5;i++){
        printf("%d ", a[i]);
    }
}


