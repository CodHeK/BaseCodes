#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;

};

struct node *search(struct node* root, int x)
{
    if(root == NULL) {
        printf("NO\n");
        return;
    }
    if(root->data == x)
        printf("YES\n");
    else {
        if(x < root->data) 
            return search(root->left, x);

        if(x > root->data)
            return search(root->right, x);
    }
}

struct node *makeBST(struct node* root, int x)
{
    if(root == NULL) {
        struct node* tmp = (struct node*)malloc(sizeof(struct node));
        tmp->data = x;
        tmp->left = NULL;
        tmp->right = NULL;
        root = tmp;
    }
    else {
        if(x < root->data) 
            root->left = makeBST(root->left,x);
        else if(x > root->data)
            root->right = makeBST(root->right,x);
    }
    return root;
}

void inorder(struct node* root)
{
    if(root == NULL)
        return;
    else {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}


int main()
{
    struct node* root = NULL;
    int n,x;
    scanf("%d",&n);
    while(n--) {
        scanf("%d",&x);
        root = makeBST(root,x);
    }    
    inorder(root);
    int s;
    scanf("%d",&s);
    search(root,s);    
    return 0;
}