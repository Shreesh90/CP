#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* start1 = NULL;
struct node* start2 = NULL;
struct node* temp;

struct node* createNode(int x){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void Insert(int x){
    struct node* newNode = createNode(x);
    if(start1 == NULL){
        start2 = start1 = newNode;
        return;
    }
    start2->prev = newNode;
    newNode->next = start2;
    start2 = newNode; 
}

void display_forward(){
    temp = start1;
    if(start1 ==NULL) return;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}

void display_reverse(){
    temp = start2;
    if(start2 == NULL) return;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    Insert(2);
    Insert(5);
    Insert(1);
    Insert(8);

    display_forward();
    printf("\n");
    display_reverse();
}