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
void display(){
    temp = start;
    while(temp!= NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
void length(){
    temp = start;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    printf("Length of list is: %d",len);
}

void delNode(int n){
    temp = start;
    struct node* temp2 = start;
    int i;
    for(i=1;i<n-1;i++){     // considering 1 based indexing
        temp = temp->next;
    }

    for(i=1;i<n;i++){
        temp2 = temp2->next;
    }

    temp->next = temp2->next;
}

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        input();
    }
    display();
        printf("\n\n");
    length();
        printf("\n");
    delNode(3);
        printf("\n");
    display();
}
