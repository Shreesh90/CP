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

// FUNCTION TO FIND SUM OF LEAF NODES
int SumOfLeaves(struct BstNode* root,int sum){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) 
        return root->data;    
    sum += SumOfLeaves(root->left,sum);
    sum += SumOfLeaves(root->right,sum);
    return sum;
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

    int sum = 0;
    sum = SumOfLeaves(root,sum);
    printf("Sum of all the Leaves are: %d",sum);
}




