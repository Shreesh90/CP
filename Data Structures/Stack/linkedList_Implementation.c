#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* top = NULL;
struct node* temp;

void push(int x){
    // temp = top;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

void pop(){
    temp = top;
    if(top == NULL) return;
    top = top->next;
    free(temp);
}

void display(){
    temp = top;
    if(top == NULL) return;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void top_element(){
    if(top == NULL) return;
    printf("%d", top->data);
}

void isEmpty(){
    if(top == NULL) printf("Empty");
    else printf("Not Empty");
}

int main()
{
    push(10);
    push(2);
    push(4);
    push(7);
    pop();
    push(0);
    push(8);
    pop();
    pop();
    pop();
    pop();
    pop();
    top_element();
    isEmpty();

}

