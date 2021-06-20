#include<stdio.h>
#include<stdlib.h>

struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
    struct BstNode* parent;
};

struct BstNode* CreateNode(struct BstNode* root,int data){
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->parent = root;
    return newNode;
}

struct BstNode* Insert(struct BstNode* root,int data){
    if(root == NULL)
        root = CreateNode(root,data);
    else if(data < root->data)
        root->left = Insert(root->left,data);
    else
        root->right = Insert(root->right,data);
    return root;
}

// FUNCTIONS TO FIND DISTANCE

int DistanceFromRoot(struct BstNode* root,int data){
    int dist = 0;
    if(data == root->data) return dist;
    else if(data < root->data){
        dist = DistanceFromRoot(root->left,data);
        dist++;
    }
    else if(data > root->data){
        dist = DistanceFromRoot(root->right,data);
        dist++;
    }
    return dist;

}

void Distance(struct BstNode* root,int a,int b){
    if(a > root->data && b > root->data)
        Distance(root->right,a,b);
    else if(a < root->data && b < root->data)
        Distance(root->left,a,b);
    else{
        int Dist_a = DistanceFromRoot(root,a);
        int Dist_b = DistanceFromRoot(root,b);
        printf("Distance between Nodes %d and %d is: %d",a,b,Dist_a + Dist_b);
    }
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

    int a,b;
    struct BstNode* add1 = NULL;
    struct BstNode* add2 = NULL;
    printf("Enter Key Values to find distance between them: ");
    scanf("%d %d",&a,&b);
    
    Distance(root,a,b);
}