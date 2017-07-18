#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* insert_At_Beg(struct node* head, int x)
{
	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	tmp->data = x;
	tmp->next = head;
	head = tmp;
	return head;
}

struct node* insert_At_end(struct node* head, int x)
{
    struct node *tmp, *p;
    tmp = (struct node*)malloc(sizeof(struct node));
    p = head;

    tmp->data = x;
    if(head == NULL) {
        tmp->next = head;
        head = tmp;
    }
    else {
        tmp->next = NULL;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = tmp;
    }
    return head;
}

struct node* del_At_beg(struct node* head)
{
    struct node *tmp, *p;
    tmp = head;
    if(tmp == NULL)
        return;
    p = tmp->next;
    free(tmp);
    head = p;
    return head;
}

struct node* del_At_end(struct node* head)
{
    struct node* tmp = head;
    if(tmp == NULL)
        return;
    while(tmp->next->next != NULL) {
        tmp = tmp->next;
    }
    free(tmp->next);
    tmp->next = NULL;
    return head;
}

struct node* insert_At_n(struct node* head, int x, int n)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    int i;
    struct node *p = head;
    tmp->data = x;
    if(n == 1) {
        tmp->next = head;
        head = tmp;
    }
    else {
        for(i=1;i<n-1;i++) {
            p = p->next;
        }
        tmp->next = p->next;
        p->next = tmp;
    }
    return head;
}

struct node* del_At_n(struct node* head, int n)
{
    struct node* tmp = head;
    struct node* p;
    int i;
    if(n == 1) {
        head = tmp->next;
        free(tmp);
    }
    else {
        for(i=1;i<n-1;i++) {
            tmp = tmp->next;
        }
        p = tmp->next->next;
        free(tmp->next);
        tmp->next = p;
    }
    return head;
}

struct node* del_spec_node(struct node* head, struct node* n)
{
    struct node *tmp, *p;
    tmp = head;
    if(head == n) {
        head = tmp->next;
        free(tmp);
    }
    else {
        tmp = n;
        p = head;
        while(p->next != n) {
            p = p->next;
        }
        p->next = tmp->next;
        free(tmp);
    }
    return head;
}

void print(struct node* head)
{
	struct node* p = head;
	while(p != NULL) {
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	struct node* head = NULL;
	head = insert_At_Beg(head,4);
	head = insert_At_Beg(head,5);
	head = insert_At_Beg(head,6);
	print(head);
	/*head = insert_At_end(head,5);
	print(head);
	head = del_At_beg(head);
	print(head);
    head = del_At_end(head);
    print(head);
    head = insert_At_n(head,3,2);
    print(head);
    head = insert_At_n(head,10,2);
    head = insert_At_n(head,12,4);
    print(head);
    head = del_At_n(head,2);
    print(head);
    head = del_At_n(head,1);
    print(head);
    head = del_At_n(head,2);
    print(head);*/
    head = del_spec_node(head,head->next);
    print(head);
	return 0;
}
