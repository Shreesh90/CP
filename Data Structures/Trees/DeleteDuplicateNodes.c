#include<stdio.h>
#include<stdlib.h>

struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

struct BstNode* CreateNode(struct BstNode* root,int data){
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
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

//FUNCION TO DELETE NODE
struct BstNode* FindMin(struct BstNode* root){
    struct BstNode* temp = (struct BstNode*)malloc(sizeof(struct BstNode));
    temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
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
        else if(root->left = NULL){
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
    int n,i,x;
    printf("Enter Number of Nodes: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        //a[i] = x;
        root = Insert(root,a[i]);
    }

    printf("\nElements InOrder before Deletion: ");
    InOrder(root);

    //DELETING ALL DUPLICATE NODES
    int max = -100000;
    for(i=0;i<n;i++){
        if(a[i] > max)
            max = a[i];
    }
    
    int count[max+1];
    for(i=0;i<max+1;i++)
        count[i] = 0;

    for(i=0;i<n;i++)
        count[a[i]]++;

    for(i=0;i<n;i++){
        if(count[a[i]] > 1){
            while(count[a[i]] > 0){
                root = Delete(root,a[i]); 
                count[a[i]]--;  
            }  
        }
    }

    printf("\nElements InOrder after Deletion: ");
    InOrder(root);

}