void make_tree(int r, struct edge tree[MAX])
{
    int current, i;
    int count=0;
    for(i=0;i<n;i++)
    {
        pred[i]=nil;
        length[i]=infinity;
        status[i]=TEMP;
    }
    length[r]=0;
    while(1)
    {
        current=min_temp();
        if(current==NIL)
        {
            if(count==n-1)
                return;
            else
            {
                printf("graph not connected\n");
                exit(1);
            }
        }
        status[current]=PERM;
        if(current!=r)
        {
            count++;
            tree[count].u=pred[current];
            tree[count].v=current;
        }
        for(i=0;i<n;i++)
        {
            if(adj[current][i] && status[i]=TEMP)
            {
                if(adj[current][i]<length[i])
                {
                    length[i]=adj[current][i];
                    pred[i]=current;
                }
            }
        }
    }
}
int min_temp()
{
    int i;
    int mins=infinity,k=-1;
    for(i=0;i<n;i++)
    {
        if(status[i]==TEMP && length[i]<mins)
        {
            mins=length[i];
            k=i;
        }
    }
    return k;
}
