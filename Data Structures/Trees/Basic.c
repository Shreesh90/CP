// Binary Seatch Tree(BST)
#include<stdio.h>
#include<stdlib.h>

//Declaration of Node for BST
struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

//Function to create New Node to add in Tree
struct BstNode* CreateNode(int data){
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//Function to Insert New Node in Tree
struct BstNode* Insert(struct BstNode* root,int data){
    if(root == NULL){
        root = CreateNode(data);
        return root;
    }
    else if(data <= root->data){
        root->left = Insert(root->left,data);
    }
    else{
        root->right = Insert(root->right,data);
    }
    return root;
}

//Function to search an element in the tree
int Search(struct BstNode* root, int findval){
    if(root == NULL){return 0;}
    else if(findval == root->data){return 1;}
    else if(findval <= root->data){return Search(root->left,findval);}
    else {return Search(root->right,findval);}
    
}

// Function to find Minimum Element
int minElement(struct BstNode* root){
    struct BstNode* temp = (struct BstNode*)malloc(sizeof(struct BstNode));
    temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}

// Function to find Maximum Element
int maxElement(struct BstNode* root){
    struct BstNode* temp = (struct BstNode*)malloc(sizeof(struct BstNode));
    temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;
}

int max(int a, int b){
    return a > b?a:b;
}
//Function to calculate Height/Max Depth of the Tree
int BstHeight(struct BstNode* root){
    if(root == NULL){return -1;}
    else{return max(BstHeight(root->left),BstHeight(root->right))+1;}
}

int main()
{
    struct BstNode* root = NULL;
    int n,i,data,findVar;
    printf("Enter number of Nodes you want in Tree: ");
    scanf("%d",&n);

    //Taking input in BST  
    for (i = 0; i < n ; i++)
    {
        scanf("%d",&data);
        root = Insert(root,data);
    }
    
    //Minimum and Maximum element in the BST
    int min = minElement(root);
    printf("Minimum element is %d ",min);
    int max = maxElement(root);
    printf("\nMaximum element is %d", max);
    
    //Searching an element in  the BST
    printf("\nEnter a Number you want to search in Tree: ");
    scanf("%d",&findVar);
    int value = Search(root,findVar);
    if(value == 1){printf("Found");}
    else {printf("Not Found");}

    // Height or Max Depth of the Tree
    int height = BstHeight(root);
    printf("\nHeight or Maximum Depth of the Tree is %d ",height);
}