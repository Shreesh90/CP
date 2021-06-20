#include<stdio.h>
#include<stdlib.h>

struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

struct BstNode* createNode(int data){
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct BstNode* Insert(struct BstNode* root,int data){
    if(root == NULL)
        root = createNode(data);
    else if(data < root->data)
        root->left = Insert(root->left,data);
    else //if(data > root->data)
        root->right = Insert(root->right,data);
    return root;
}

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

int main()
{
    struct BstNode* root = NULL;
    int n,i,x;
    printf("Number of Nodes: ");
    scanf("%d", &n);

    for(i=0;i<n;i++){
        scanf("%d",&x);
        root = Insert(root,x);
    } 

    printf("\nElements in PreOrder are: ");
    preOrder(root);

    printf("\nElements in InOrder are: ");
    inOrder(root);

    printf("\nElements in PostOrder are: ");
    postOrder(root);

}