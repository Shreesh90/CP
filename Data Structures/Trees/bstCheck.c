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

//Functions for Checking a BST
int IsSubtreeLesser(struct BstNode* root,int data){
    if(root == NULL) return 1;
    if(root->data < data && IsSubtreeLesser(root->left,data) && IsSubtreeLesser(root->right,data))
        return 1;
    else
        return 0;
}

int IsSubtreeGreater(struct BstNode* root,int data){
if(root == NULL) return 1;
if(root->data > data && IsSubtreeGreater(root->left,data) && IsSubtreeGreater(root->right,data))
    return 1;
else
    return 0;
}

int isBST(struct BstNode* root){
    if(root == NULL) return 1;
    if(IsSubtreeLesser(root->left,root->data) && IsSubtreeGreater(root->right,root->data)
        && isBST(root->left) && isBST(root->right))
        return 1;
    else
        return 0;
}

int main()
{
    struct BstNode* root = NULL;
    int n,i,x;
    printf("Enter Number of Nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        root = Insert(root,x);
    }

    int value = isBST(root);
    if(value == 1)
        printf("The tree is a BST");
    else
        printf("Tree is not BST");
    
}