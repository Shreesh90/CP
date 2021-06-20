#include<stdio.h>
#include<stdlib.h>

struct node{
    char data;
    struct node* next;
};

struct node* top = NULL;
struct node* temp;

void stack_push(char x){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

void stack_pop(){
    temp = top;
    if(top == NULL) return;
    top = top->next;
    free(temp);
}

int stack_top_element(){
    if(top == NULL) return -1;
    return top->data;
}

void stack_isEmpty(){
    if(top == NULL) printf("Empty");
    else printf("Not Empty");
}

void reverseString(char *s, int n){
    for(int i=0;i<n;i++){
        stack_push(s[i]);
    }

    for(int i=0;i<n;i++){
        s[i] = stack_top_element();
        stack_pop();
    }
}

int main()
{
    char s[10];
    for(int i=0;i<10;i++){
        scanf("%c", &s[i]);
    }

    reverseString(s, 10);
    printf("\n");
    for(int i=0;i<10;i++){
        printf("%c", s[i]);
    }
}

