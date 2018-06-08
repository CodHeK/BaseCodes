#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
struct node {
	int data;
	struct node *right,*left;
};

struct node *createNode(struct node *root, int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
}

struct node *createBST(struct node *root, int value)
{
	if(root==NULL)
		return createNode(root, value);
	if(root->data<value)
		root->right = createBST(root->right, value);
	else if(root->data>value)
		root->left = createBST(root->left, value);
	return root;
}
bool ifBST(struct node *root, int min, int max)
{
	if(root==NULL)
		return true;
	if(root->data>max||root->data<min)
		return false;
	return ifBST(root->left,min,root->data-1)&&ifBST(root->right,root->data+1,max);
}
void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\n", root->data);
		inorder(root->right);
	}
}

int main()
{
	struct node *root = NULL;
	int n,x,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		root = createBST(root,x);
	}	

	if(ifBST(root,INT_MIN,INT_MAX)==true)
		printf("It is BST\n");
	else
		printf("It is not BST\n");
	return 0;
}