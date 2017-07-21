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
struct node *minValue(struct node *node)
{
	while(node->left!=NULL)
	{
		node = node->left;
	}
	return node;
}
struct node *remover(struct node *root, int val)
{
	if(root==NULL)
		return root;
	if(val<root->data)
	{
		root->left = remover(root->left,val);
	}
	else if(root->data<val)
	{
		root->right = remover(root->right,val);
	}
	else
	{
		if(root->left==NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			struct node *temp = root->left;
			free(root);
			return temp;
		}
		struct node *temp = minValue(root->right);
		root->data = temp->data;
		root->right = remover(root->right, temp->data);
	}
	return root;
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
	int k,y;
	printf("\n");
	inorder(root);
	scanf("%d",&k);
	
	while(k--)
	{
		scanf("%d",&y);
		root = remover(root,y);
	}
	printf("\n");
	inorder(root);
	printf("\n");
	return 0;
}