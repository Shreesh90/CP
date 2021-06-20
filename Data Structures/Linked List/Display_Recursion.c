#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* temp;
struct node* input(struct node* start){
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
    return start;
}

void reverse(struct node* start){
    struct node *prev, *current, *next;
    current = start;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    start = prev;
}

void display_recursive(struct node* start){
    if(start == NULL) return;
    printf("%d ", start->data);
    display_recursive(start->next);
}

void display_reverse_recursive(struct node* start){
    if(start == NULL) return;
    display_reverse_recursive(start -> next);
    printf("%d ", start->data);
}

int main()
{
    struct node* start = NULL;
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        start = input(start);
    }

    // reverse(start);
    display_recursive(start);
    printf("\n");
    display_reverse_recursive(start);
}