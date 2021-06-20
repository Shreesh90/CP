#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* createNode(int data){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}
struct node *temp1, *temp2;
struct node* searchparent(struct node* root, int parent,int *found){
    if(root == NULL) return root;
    if(root->data == parent) {*found=1; return root;}
    temp1 = searchparent(root->left, parent, found);
    if(*found == 1) return temp1;
    temp2 = searchparent(root->right, parent, found);
    if(*found == 1) return temp2;
}

struct node* Insert(struct node* root, int parent, int child, char dir){
    
	if(root == NULL){
		root = createNode(parent);
		if(int(dir) == int('L'))
			root->left = createNode(child);
		else
			root->right = createNode(child);
		return root;
	}
    int found = 0;
    struct node* temp = searchparent(root, parent,&found);

	if(temp->data == parent){
		if(int(dir) == ('L'))
			temp->left = createNode(child);
		else
			temp->right = createNode(child);
		return root;
	}
	
}

int IsSubtreeLesser(struct node* root, int data){
	if(root == NULL) return 1;
	if(root->data < data && IsSubtreeLesser(root->left, data) && IsSubtreeLesser(root->right, data))
		return 1;
	else
		return 0;
}

int IsSubtreeGreater(struct node* root, int data){
	if(root == NULL) return 1;
	if(root->data > data && IsSubtreeGreater(root->left,data) && IsSubtreeGreater(root->right, data))
		return 1;
	else	
		return 0;
}

int isBst(struct node* root){
	if(root == NULL) return 1;
	if(IsSubtreeLesser(root->left,root->data) && IsSubtreeGreater(root->right, root->data) && isBst(root->left) && isBst(root->right))
		return 1;
	else
		return 0;
}

int main()
{
	struct node* root = NULL;
	int n,parent,child;
	char dir;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>parent>>child>>dir;
		root = Insert(root,parent,child,dir);
	}
    // cout<<"check";
	int ans = isBst(root);
	cout<<!ans;
}