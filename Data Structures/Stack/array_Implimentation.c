#include<stdio.h>
#define size 10
int top = -1;
int a[size];


void push(int x){
    if(top == size-1){printf("Stack Overflow");return;}
    a[++top] = x;
}

void pop(){
    if(top == -1){printf("The stack is empty.");return;}
    top--;
}

void print(){
    int i;
    for(i=0;i<=top;i++)
        printf("%d ",a[i]);
}

int main()
{
    push(10);
    push(5);
    push(2);
    pop();
    push(7);
    push(1);
    push(0);
    pop();
    push(0);
    push(10);
    print();
}


