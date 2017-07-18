#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

struct node *insertAtBeg(struct node* head, int x)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = x;
    if(head == NULL) {
        tmp->prev = NULL;
        tmp->next = NULL;
        head = tmp;
        return head;
    }
    else {
        tmp->next = head;
        tmp->prev = NULL;
        head->prev = tmp;
        head = tmp;
        return head;
    }
};

struct node *insertAtEnd(struct node* head, int x)
{
    struct node *tmp,*p;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = x;
    if(head == NULL) {
        tmp->next = NULL;
        tmp->prev = NULL;
        head = tmp;
        return head;
    }
    else {
        p = head;
        while(p->next != NULL) {
            p = p->next;
        }
        tmp->next = NULL;
        p->next = tmp;
        return head;
    }
};

struct node *delAtBeg(struct node* head)
{
    struct node *tmp;
    if(head == NULL) {
        return;
    }
    else {
        tmp = head;
        head = tmp->next;
        tmp->next->prev = NULL;
        return head;
    }
};

struct node *addAtN(struct node* head, int x, int N)
{
    struct node *tmp,*p;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = x;
    if(N == 1) {
        tmp->prev = NULL;
        tmp->next = head;
        head->prev = tmp;
        head = tmp;
        return head;
    }
    else {
        int i;
        p = head;
        for(i = 1;i < N - 2;i++) {
            p = p->next;
        }
        tmp->next = p->next;
        p->next = tmp;
        tmp->prev = p;
        p->next->prev = tmp;
        return head;
    }
};

struct node* delAtN(struct node* head, int N)
{
    struct node *tmp,*p;
    tmp = head;
    if(head == NULL) {
        return;
    }
    else {
        if(N == 1) {
            p = tmp->next;
            p->prev = NULL;
            head = head->next;
            free(tmp);
            return head;
        }
        else if(tmp->next->next == NULL && N == 2) {
            p = tmp->next;
            tmp->next = NULL;
            free(p);
            return head;
        }
        else {
            int i;
            for(i = 1;i < N - 2;i++) {
                tmp = tmp->next;
            }
            p = tmp->next;
            tmp->next = p->next;
            p->next->prev = tmp;
            free(p);
            return head;
        }
    }
};

struct node *delAtEnd(struct node* head)
{
    struct node *tmp,*p;
    if(head == NULL) {
        return;
    }
    else {
        tmp = head;
        while(tmp->next->next != NULL) {
            tmp = tmp->next;
        }
        p = tmp->next;
        tmp->next = NULL;
        free(p);
        return head;
    }
};

void print(struct node* head)
{
    struct node* tmp = head;
    while(tmp != NULL) {
        printf("%d <-> ",tmp->data);
        tmp = tmp->next;
    }
      printf(" NULL");
    printf("\n");
}

int main()
{
    struct node* head = NULL;
    int n,element,i;
    head = insertAtBeg(head,6);
    head = insertAtBeg(head,8);
    print(head);
    head = insertAtEnd(head,16);
    head = insertAtEnd(head,18);
    print(head);
    head = delAtBeg(head);
    print(head);
    head = delAtEnd(head);
    print(head);
    head = addAtN(head,33,2);
    print(head);
    head = addAtN(head,33,3);
    print(head);
    head = delAtN(head,3);
    print(head);
    head = delAtN(head,2);
    print(head);
    return 0;
}