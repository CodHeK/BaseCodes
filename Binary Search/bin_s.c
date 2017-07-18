#include <stdio.h>
#include <stdlib.h>

int bin_s(int a[], int l, int r, int x)
{
    if(l < r) {
    int m = (l+r)/2;
    if(a[m] == x)
        return m;
    else {
        if(a[m] > x)
            return bin_s(a,l,m-1,x);
        else
            return bin_s(a,m+1,r,x);
    }
    }
}

int main()
{
    int a[] = {3,5,6,7,77,99,122,134};
    printf("%d\n",bin_s(a,0,7,134));
    return 0;
}
