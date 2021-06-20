#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* front = NULL;
struct node* rear = NULL;
struct node* temp;

void Enqueue(int x){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->link = NULL;
    if(rear == NULL)
        front = rear = newNode;
    else{
        rear->link = newNode;
        rear = newNode;
    }
}

void Dequeue(){
    if(front == NULL) return;
    temp = front;
    front = front->link;
    free(temp);
}

void peek(){
    if(front == NULL) return;
    printf("%d",front->data);
}

void IsEmpty(){
    if(front == NULL) printf("Queue Empty");
    else printf("Queue not Empty");
}

int main()
{
    Enqueue(3);
    Enqueue(4);
    Enqueue(8);
    Enqueue(1);
    Dequeue();
    Enqueue(6);
    Enqueue(2);
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    peek();
    IsEmpty();
}


