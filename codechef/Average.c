#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i,j,m,c=0,min,max;
    int k,a[10000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(i==0)
        {
            max=a[0];
            min=a[0];
        }
        else
        {
            if(a[i] > max)
                {
                    max = a[i];
                }
            else if(a[i]<min)
            {
                min=a[i];
            }
        }
    }
    for(i=0;i<(n-1);i++)
    {
        for(j = i+1 ; j < n ; j++)
        {
            if(((a[i]+a[j])%2) == 0)
            {
            k = (a[i]+a[j])/2;
            if( k <= max && k >= min)
                {
                for(m=0;m<n;m++)
                    {
                        if(k == (a[m]))
                            {
                                c++;
                            }
                    }
                }
            }
        }
    }
    printf("%d",c);
 return 0;
}
