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

struct node* del_Alt(struct node* head)
{
    struct node *tmp, *p;
    tmp = head;
    while(tmp != NULL) {
        p = tmp->next;
        tmp->next = p->next;
        free(p);
        tmp = tmp->next;
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
	head = insert_At_Beg(head,14);
	head = insert_At_Beg(head,15);
	head = insert_At_Beg(head,16);
    print(head);
    head = del_Alt(head);
    print(head);
    return 0;
}
