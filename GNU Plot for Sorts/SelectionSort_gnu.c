#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int sort(int* a,int f,int l)
{
    int i,j,k,x,o;
    for(i=f;i<l;i++)
    {
        k=i;
        x=a[i];
        for(j=i+1;j<=l;j++)
        {
            if(a[j]<x)
            {
                x=a[j];
                k=j;
            }
        }
    }
    return 0;
}
int main()
{
    clock_t start;
    clock_t end;

    float time;
   
    FILE* fp = NULL;
    fp = fopen("sel.txt","w+");


    int n=100,i;
    while(n<=1000000) {
    int a[n];
    for(i=0;i<n;i++)
        a[i] = rand()%10000000;
    start = clock();
    sort(a,0,n-1);
    end = clock();
   
    time = (float)(end - start);

    fprintf(fp,"%d      %f\n",n,time);

    n += 100;
}
    return 0;
}



//To run plot on gnuplot --->  plot "filename.txt" using 1:2 with lines;
