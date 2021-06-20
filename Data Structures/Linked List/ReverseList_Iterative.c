#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* start = NULL;
struct node* temp;
void input(){
    temp = start;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = NULL;
    scanf("%d",&(newNode->data));
    if(temp == NULL)
        start = newNode;
    else if(temp != NULL){
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void reverse(){
    struct node *prev, *current, *next;
    current = start;
    prev = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    start = prev;
}

void display(){
    temp = start;
    while(temp!= NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        input();
    }

    reverse();
    display();
}