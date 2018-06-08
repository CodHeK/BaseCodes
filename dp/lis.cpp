#include<iostream>
using namespace std;

int lis(int a[], int n)
{
    int i, j;

    //create an array b of size n ie, b[n]
    //b[i] represents the value of longest increasing subsequence with a[i] being the last element

    //b[i]=longest increasing subsequence for the array a[0...i] by including a[i] in the subseuence
    //at the end

    int b[n];

    //Since, we are definitely including a[i] for the calculation of b[i], b[i] will
    //either be equal to 1 or greater than 1
    //so, initialize b
    for(i=0;i<n;i++)
        b[i]=1;


    //now, we have to fill this b array

    //we will calulate the value of b[i] for every 1<=i<=n by checking whether any subsequence
    //b[0], b[1],...,b[i-1] can fit before a[i] and then selecting the maximum out of them
    for(i=1;i<n;i++)
    {
        //for every i, we will check all values of 0<=j<i for subsequences b[j] to which a[i]
        //could be appended and select the longest one
        for(j=0;j<i;j++)
        {
            //if the current element ie, the ith element has value greater than jth element, that
            //means a[i] can be appended after b[j]
            //Since, we are interested in finding the longest of such subsequences, we will consider
            //only those values of b[j] that are greater than or equal to b[i]
            if(a[i]>a[j] && b[i]<b[j]+1)
            {
                b[i]=b[j]+1;
            }
        }
    }

    //now, we have calculated all the values of b[i] for 0<=i<n
    //The length of the longest increasing subsequence of the given array is the maximum of all
    //these values because the longest increasing subsequence can end with any element of the array

    //finding maximum element in b array
    int max=0;

    for(i=0;i<n;i++)
    {
        if(b[i]>max)
            max=b[i];
    }

    return max;


}

int main()
{
    int i,n;

    cout<<"Enter the no. of elements ";
    cin>>n;

    int a[n];

    cout<<"Enter the values"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int result=lis(a,n);

    cout<<"The number of terms in the longest increasing subsequence is "<<result;

    return 0;
}
