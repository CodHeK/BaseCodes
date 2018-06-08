#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *left, *right;
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

int search(struct node *root, int y)
{
	if(root==NULL)
		return 0;
	if(root->data==y)
		return 1;
	else if(root->data>y)
		search(root->left, y);
	else if(root->data<y)
		search(root->right,y);
}
void mirror(struct node *root)
{
	if(root==NULL)
		return;
	else
	{
		mirror(root->right);
		mirror(root->left);
		struct node *temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
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
	inorder(root);
	printf("\n");
	mirror(root);
	inorder(root);
	return 0;
}