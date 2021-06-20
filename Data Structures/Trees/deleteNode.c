#include<stdio.h>
#include<stdlib.h>

struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

struct BstNode* CreateNode(int data){
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct BstNode* Insert(struct BstNode* root,int data){
    if(root == NULL)
        root = CreateNode(data);
    else if(data < root->data)
        root->left = Insert(root->left,data);
    else
        root->right = Insert(root->right,data);
    return root;
}

// FUNCTION TO DELETE A NODE
struct BstNode* FindMin(struct BstNode* root){
    struct BstNode* temp = root;
    while(temp->left != NULL)
        temp = temp->left;
    return temp;
}
struct BstNode* Delete(struct BstNode* root,int del){
    if(root == NULL) return root;
    else if(del < root->data) root->left = Delete(root->left,del);
    else if(del > root->data) root->right = Delete(root->right,del);
    else{
        //CASE-1: NO CHILD
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        //CASE-2: ONE CHILD
        else if(root->left == NULL){
            struct BstNode* temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL){
            struct BstNode* temp = root;
            root = root->left;
            free(temp);
        }
        //CASE-3: TWO CHILD
        else{
            struct BstNode* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right,temp->data);
        }
    }
    return root;
}

//DISPLAY
void InOrder(struct BstNode* root){
    if(root == NULL) return;
    InOrder(root->left);
    printf("%d ",root->data);
    InOrder(root->right);
    return;
}

int main()
{
    struct BstNode* root = NULL;
    int n,i,x,del;
    printf("Enter Number of Nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        root = Insert(root,x);
    }

    printf("\nElements InOrder before Deletion: ");
    InOrder(root);

    //COMMAND TO DELETE NODE
    printf("\nEnter a Node value to delete: ");
    scanf("%d",&del);
    root = Delete(root,del);

    printf("\nElements InOrder after Deletion: ");
    InOrder(root);
}