#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
int n;
scanf("%d",&n);
int i,root,left,right;
int k =1;
int arr[n+1];
for(i=1;i<=n;i++)
scanf("%d",&arr[i]);
for(i=1;i<=n/2;i++)
{
if(2*i<=n)
{
if((2*i+1)<=n)
{
root = arr[i];
left = arr[2*i];
right = arr[2*i+1];
if(left<=root&&right<=root)
{
k=1;
continue;
}
else
{
k = 0;
break;
}
}
else
{
root = arr[i];
left = arr[2*i];
if(left<=root)
{
k=1;
continue;
}
else
{
k = 0;
break;
}
}
}
}
if(k==0)
printf("no\n");
else
printf("yes\n");
return 0;
}




