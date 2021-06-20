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

// FUNCTION TO CHECK A SUM-TREE

void sumTree(struct BstNode* root){
    if(root == NULL) return 0;
    if(root->left != NULL && root->right != NULL)
        return root->data;

    int v1 = sumTree(root->left);
    int v2 = sumTree(root->right);

    if(v1 + v2 == root->data)
        v1 = v1+v2;
        
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


}