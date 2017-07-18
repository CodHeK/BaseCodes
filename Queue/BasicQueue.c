#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* enqueue(struct node* head, int x)
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

struct node* dequeue(struct node* head)
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

int front(struct node* head)
{
    struct node* tmp = head;
    printf("Front = %d\n",tmp->data);
}

int rear(struct node* head)
{
    struct node* tmp = head;
    while(tmp->next !=NULL) {
        tmp = tmp->next;
    }
    printf("Rear = %d\n",tmp->data);
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
    head = enqueue(head,3);
    head = enqueue(head,4);
    head = enqueue(head,12);
    head = enqueue(head,5);
    print(head);
    front(head);
    rear(head);
    head = dequeue(head);
    head = dequeue(head);
    print(head);
    front(head);
    rear(head);
    return 0;
}
