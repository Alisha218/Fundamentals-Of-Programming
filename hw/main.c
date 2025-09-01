#include <stdio.h>
#include <stdlib.h>

int main()
{
     int n1,n2,sum=0;
     printf("enter n1: ");
     scanf("%d",&n1);
     printf("enter n2: ");
     scanf("%d",&n2);
     for (int i=n1 ;i<=n2;i++)
        if (i%2 != 0)
            sum += i;

    printf("%d", sum);



    return 0;
}
