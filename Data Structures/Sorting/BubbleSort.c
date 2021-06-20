//Time Complexity - O(n2)
#include<stdio.h>

void swap(int *a, int i,int j){
    int t;
    t = a[i];
    a[i] = a[j];
    a[j] = t;
}
void bubbleSort(int *a, int n){
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n-1 ; j++){
            if(a[j] > a[j+1])
                swap(a,j,j+1);
        }
    }
}

int main()
{
    int a[5] = {4,2,3,5,1};
    bubbleSort(a,5);
    for(int i=0;i<5;i++){
        printf("%d ", a[i]);
    }
}