#include <stdio.h>
#include <stdlib.h>

void push(int stack[], int data, int n,int *top)
{
    if(*top == n-1) {
        return;
    }
    else {
        *top = *top + 1;
        stack[*top] = data;
    }
}

void pop(int stack[], int *top)
{
    if(*top == -1)
        return;
    else
        *top = *top - 1;
}

int top_el(int stack[],int *top)
{
    return *top;
}

int size(int stack[], int *top)
{
    return (*top)+1;
}

int isEmpty(int stack[], int *top)
{
    if(*top == -1)
        return 1;
    else
        return 0;
}

void print(int stack[], int *top)
{
    int i;
    for(i=0;i<(*top)+1;i++) {
        printf("%d",stack[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    int *top = -1;
    int a[100],i;
    /*for(i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }*/
    push(a,3,100,&top);
    push(a,4,100,&top);
    push(a,5,100,&top);
    print(a,&top);
    pop(a,&top);
    print(a,&top);
    return 0;
}

