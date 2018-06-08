#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *left, *right;
};

struct node *createNode(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}


int sum(struct node *root)
{
	if(root==NULL)
		return 0;
	return root->data+sum(root->left)+sum(root->right);
}

int Sumtree(struct node *root)
{
		if(root==NULL||(root->left==NULL&&root->right==NULL))
			return 1;
		int ls = sum(root->left);
		int rs = sum(root->right);
		if(root->data==ls+rs&&Sumtree(root->left)&&Sumtree(root->right))
			return 1;
		return 0;
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
	root = createNode(80);
	root->left = createNode(30);
	root->left->left = createNode(5);
	root->left->left->left = createNode(2);
	root->left->left->right = createNode(3);
	root->left->right = createNode(20);
	root->right = createNode(10);
	root->right->left = createNode(5);
	root->right->right = createNode(5);
	
	if(Sumtree(root)==1)
	{
		printf("SumTree\n");
	}
	else
	{
		printf("Not Sumtree\n");
	}
	return 0;
}