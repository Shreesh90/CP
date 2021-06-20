#include<stdio.h>
#include<stdlib.h>

//Functions for Tree
struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

struct BstNode* CreateNode(int data){
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data =  data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct BstNode* Insert(struct BstNode* root, int data){
    if(root == NULL)
        return CreateNode(data);
    else if(data < root->data)
        root->left = Insert(root->left,data);
    else
        root->right = Insert(root->right,data);
    return root;
}

//Functions for Queue
struct queue{
    struct BstNode* data;
    struct queue* link;  
};
struct queue* head = NULL;
struct queue* tail = NULL;
struct queue* temp;

void push(struct BstNode* root){
    struct queue* temp = (struct queue*)malloc(sizeof(struct queue));
    temp->data = root;
    temp->link = NULL;
    if(head == NULL && tail == NULL)
        tail = head =  temp; 
    
    tail->link = temp;
    tail = temp;
}
void pop(){
    if(head == NULL) return;
    temp = head;
    head = head->link;
    free(temp);
}
struct BstNode* front(){
    return head->data;
}
int isEmpty(){
    if(head == NULL)
        return 1;
    else
        return 0;
}

//Function for BFS or Level-Order Search
void LevelOrder(struct BstNode* root){
    
    if(root == NULL) return;
    push(root);
    while(!isEmpty()){
        struct BstNode* current = front();
        printf("%d ",current->data);
        if(current->left != NULL) push(current->left);
        if(current->right != NULL) push(current->right);
        pop();
    }
    return;
}

//DFS Code
//PreOrder
void preOrder(struct BstNode* root){
    if(root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

//Inorder
void inOrder(struct BstNode* root){
    if(root == NULL) return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right); 
}

//PostOrder
void postOrder(struct BstNode* root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}

//Functions to find Median in tree
void inOrder_Median(struct BstNode* root, int *arr, int *i){
    if(root == NULL) return;
    inOrder_Median(root->left, arr, i);
    arr[(*i)++] = root->data;
    // printf("%d ",root->data);
    inOrder_Median(root->right, arr, i);
}

int Median(struct BstNode* root, int n){
    if(root == NULL) return -1;
    int i = 0;
    int arr[n];
    inOrder_Median(root, arr, &i);
    return arr[n/2];
}

int main()
{
    struct BstNode* root = NULL;
    int i,n,findVar,x;
    printf("Number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        root = Insert(root,x);
    }

    printf("Elements of Tree in BFS Order are: ");
    LevelOrder(root);

    printf("\nElements in PreOrder are: ");
    preOrder(root);

    printf("\nElements in InOrder are: ");
    inOrder(root);

    printf("\nElements in PostOrder are: ");
    postOrder(root);

    int med = Median(root, n);
    printf("\nMedian of tree is: %d", med);

}